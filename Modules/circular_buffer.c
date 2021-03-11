/*
 * circular_buffer.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Eren
 */
#include "stm32f0xx_hal.h"
#include"stdbool.h"
#include"circular_buffer.h"
#include <stdbool.h>
typedef struct circular_buf_t circular_buf_t;
 typedef  circular_buf_t* cbuf_handle_t;
 struct circular_buf_t
 {
	 uint32_t *buffer;
	 size_t head;
	 size_t tail;
	 size_t max;
	 bool full;
 };
 cbuf_handle_t circular_buf_init(uint32_t* buffer, size_t size)
 {
volatile cbuf_handle_t cbuf =malloc(sizeof(cbuf_handle_t));
	assert(cbuf);// buffer initialized?
	cbuf->buffer=buffer;
	cbuf->max=size;
	circular_buf_reset(cbuf);
	assert(circular_buf_empty(cbuf));
	return cbuf;
 }
 void circular_buf_reset(cbuf_handle_t cbuf)
 {
	 assert(cbuf);// buffer initialized?
	 cbuf->head=0;
	 cbuf->tail=0;
	 cbuf->full=false;
 }
 void circular_buf_free(cbuf_handle_t cbuf)
 {
	 assert(cbuf); //buffer initialized to free?
	 free(cbuf);
 }
 bool circular_buf_full(cbuf_handle_t cbuf)
 {
	 assert(cbuf);
	 return cbuf->full;
 }
 bool circular_buf_empty(cbuf_handle_t cbuf)
{
	assert(cbuf);
	return (!(cbuf->full) && (cbuf->head == cbuf->tail)); // full or empty?

}
 size_t circular_buf_capacity(cbuf_handle_t cbuf)
{
	assert(cbuf);
	return cbuf->max;

}
 size_t circular_buf_size(cbuf_handle_t cbuf)
{
	assert(cbuf);
	size_t size = cbuf->max;
	if(!cbuf->full)
	{
		if(cbuf->head>=cbuf->tail)
		{
			size=(cbuf->head-cbuf->tail);
		}
		else
		{
			size=(cbuf->max+cbuf->head-cbuf->tail);//data consumed
		}
	}
	return size;

}
 static void advance_pointer(cbuf_handle_t cbuf)
{
	assert(cbuf);
	if(cbuf->full)
	{
		cbuf->tail=(cbuf->tail+1) %cbuf->max;
	}
	cbuf->head=(cbuf->head+1)&cbuf->max;
	cbuf->full=(cbuf->head==cbuf->tail);

}
 static void retreat_pointer(cbuf_handle_t cbuf)
{
	assert(cbuf);
	cbuf->full=false;
	cbuf->tail=(cbuf->tail+1)%cbuf->max;
}
void circular_buf_put(cbuf_handle_t cbuf, uint32_t data)
{
	assert(cbuf&& cbuf->buffer);
	cbuf->buffer[cbuf->head]=data;
	advance_pointer(cbuf);
}

int circular_buf_get(cbuf_handle_t cbuf ,uint32_t *data)
{
	assert(cbuf&&data&&cbuf->buffer);
	int r=-1;

	if(!circular_buf_empty(cbuf))
	{
		*data=cbuf->buffer[cbuf->tail];
		retreat_pointer(cbuf);
		r=0;
	}
}


















