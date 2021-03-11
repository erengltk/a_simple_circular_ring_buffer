/*
 * circular_buffer.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Eren
 */
#include"stdbool.h"
#ifndef MODULES_CIRCULAR_BUFFER_H_
#define MODULES_CIRCULAR_BUFFER_H_
typedef struct circular_buf_t circular_buf_t;
typedef circular_buf_t* cbuf_handle_t;
cbuf_handle_t circular_buf_init(uint32_t* buffer, size_t size);
void circular_buf_free(cbuf_handle_t cbuf);
void circular_buf_reset(cbuf_handle_t cbuf);
void circular_buf_put(cbuf_handle_t cbuf, uint32_t data);
int circular_buf_get(cbuf_handle_t cbuf, uint32_t * data);
bool circular_buf_empty(cbuf_handle_t cbuf);
bool circular_buf_full(cbuf_handle_t cbuf);
size_t circular_buf_capacity(cbuf_handle_t cbuf);
size_t circular_buf_size(cbuf_handle_t cbuf);

#endif /* MODULES_CIRCULAR_BUFFER_H_ */
