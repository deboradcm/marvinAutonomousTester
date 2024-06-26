// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_marvin_interfaces:action/Hover.idl
// generated code does not contain a copyright notice
#include "action_marvin_interfaces/action/detail/hover__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
action_marvin_interfaces__action__Hover_Goal__init(action_marvin_interfaces__action__Hover_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    action_marvin_interfaces__action__Hover_Goal__fini(msg);
    return false;
  }
  // initial_x
  // initial_y
  // initial_z
  // final_x
  // final_y
  // final_z
  return true;
}

void
action_marvin_interfaces__action__Hover_Goal__fini(action_marvin_interfaces__action__Hover_Goal * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // initial_x
  // initial_y
  // initial_z
  // final_x
  // final_y
  // final_z
}

bool
action_marvin_interfaces__action__Hover_Goal__are_equal(const action_marvin_interfaces__action__Hover_Goal * lhs, const action_marvin_interfaces__action__Hover_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // initial_x
  if (lhs->initial_x != rhs->initial_x) {
    return false;
  }
  // initial_y
  if (lhs->initial_y != rhs->initial_y) {
    return false;
  }
  // initial_z
  if (lhs->initial_z != rhs->initial_z) {
    return false;
  }
  // final_x
  if (lhs->final_x != rhs->final_x) {
    return false;
  }
  // final_y
  if (lhs->final_y != rhs->final_y) {
    return false;
  }
  // final_z
  if (lhs->final_z != rhs->final_z) {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Goal__copy(
  const action_marvin_interfaces__action__Hover_Goal * input,
  action_marvin_interfaces__action__Hover_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // initial_x
  output->initial_x = input->initial_x;
  // initial_y
  output->initial_y = input->initial_y;
  // initial_z
  output->initial_z = input->initial_z;
  // final_x
  output->final_x = input->final_x;
  // final_y
  output->final_y = input->final_y;
  // final_z
  output->final_z = input->final_z;
  return true;
}

action_marvin_interfaces__action__Hover_Goal *
action_marvin_interfaces__action__Hover_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Goal * msg = (action_marvin_interfaces__action__Hover_Goal *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_Goal));
  bool success = action_marvin_interfaces__action__Hover_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_Goal__destroy(action_marvin_interfaces__action__Hover_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_Goal__Sequence__init(action_marvin_interfaces__action__Hover_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Goal * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_Goal *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_Goal__Sequence__fini(action_marvin_interfaces__action__Hover_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_Goal__Sequence *
action_marvin_interfaces__action__Hover_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Goal__Sequence * array = (action_marvin_interfaces__action__Hover_Goal__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_Goal__Sequence__destroy(action_marvin_interfaces__action__Hover_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_Goal__Sequence__are_equal(const action_marvin_interfaces__action__Hover_Goal__Sequence * lhs, const action_marvin_interfaces__action__Hover_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Goal__Sequence__copy(
  const action_marvin_interfaces__action__Hover_Goal__Sequence * input,
  action_marvin_interfaces__action__Hover_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_Goal * data =
      (action_marvin_interfaces__action__Hover_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
action_marvin_interfaces__action__Hover_Result__init(action_marvin_interfaces__action__Hover_Result * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    action_marvin_interfaces__action__Hover_Result__fini(msg);
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
action_marvin_interfaces__action__Hover_Result__fini(action_marvin_interfaces__action__Hover_Result * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // x
  // y
  // z
}

bool
action_marvin_interfaces__action__Hover_Result__are_equal(const action_marvin_interfaces__action__Hover_Result * lhs, const action_marvin_interfaces__action__Hover_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Result__copy(
  const action_marvin_interfaces__action__Hover_Result * input,
  action_marvin_interfaces__action__Hover_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

action_marvin_interfaces__action__Hover_Result *
action_marvin_interfaces__action__Hover_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Result * msg = (action_marvin_interfaces__action__Hover_Result *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_Result));
  bool success = action_marvin_interfaces__action__Hover_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_Result__destroy(action_marvin_interfaces__action__Hover_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_Result__Sequence__init(action_marvin_interfaces__action__Hover_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Result * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_Result *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_Result__Sequence__fini(action_marvin_interfaces__action__Hover_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_Result__Sequence *
action_marvin_interfaces__action__Hover_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Result__Sequence * array = (action_marvin_interfaces__action__Hover_Result__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_Result__Sequence__destroy(action_marvin_interfaces__action__Hover_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_Result__Sequence__are_equal(const action_marvin_interfaces__action__Hover_Result__Sequence * lhs, const action_marvin_interfaces__action__Hover_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Result__Sequence__copy(
  const action_marvin_interfaces__action__Hover_Result__Sequence * input,
  action_marvin_interfaces__action__Hover_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_Result * data =
      (action_marvin_interfaces__action__Hover_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
action_marvin_interfaces__action__Hover_Feedback__init(action_marvin_interfaces__action__Hover_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    action_marvin_interfaces__action__Hover_Feedback__fini(msg);
    return false;
  }
  // current_x
  // current_y
  // current_z
  return true;
}

void
action_marvin_interfaces__action__Hover_Feedback__fini(action_marvin_interfaces__action__Hover_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // current_x
  // current_y
  // current_z
}

bool
action_marvin_interfaces__action__Hover_Feedback__are_equal(const action_marvin_interfaces__action__Hover_Feedback * lhs, const action_marvin_interfaces__action__Hover_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // current_x
  if (lhs->current_x != rhs->current_x) {
    return false;
  }
  // current_y
  if (lhs->current_y != rhs->current_y) {
    return false;
  }
  // current_z
  if (lhs->current_z != rhs->current_z) {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Feedback__copy(
  const action_marvin_interfaces__action__Hover_Feedback * input,
  action_marvin_interfaces__action__Hover_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // current_x
  output->current_x = input->current_x;
  // current_y
  output->current_y = input->current_y;
  // current_z
  output->current_z = input->current_z;
  return true;
}

action_marvin_interfaces__action__Hover_Feedback *
action_marvin_interfaces__action__Hover_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Feedback * msg = (action_marvin_interfaces__action__Hover_Feedback *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_Feedback));
  bool success = action_marvin_interfaces__action__Hover_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_Feedback__destroy(action_marvin_interfaces__action__Hover_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_Feedback__Sequence__init(action_marvin_interfaces__action__Hover_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Feedback * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_Feedback *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_Feedback__Sequence__fini(action_marvin_interfaces__action__Hover_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_Feedback__Sequence *
action_marvin_interfaces__action__Hover_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_Feedback__Sequence * array = (action_marvin_interfaces__action__Hover_Feedback__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_Feedback__Sequence__destroy(action_marvin_interfaces__action__Hover_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_Feedback__Sequence__are_equal(const action_marvin_interfaces__action__Hover_Feedback__Sequence * lhs, const action_marvin_interfaces__action__Hover_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_Feedback__Sequence__copy(
  const action_marvin_interfaces__action__Hover_Feedback__Sequence * input,
  action_marvin_interfaces__action__Hover_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_Feedback * data =
      (action_marvin_interfaces__action__Hover_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "action_marvin_interfaces/action/detail/hover__functions.h"

bool
action_marvin_interfaces__action__Hover_SendGoal_Request__init(action_marvin_interfaces__action__Hover_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_marvin_interfaces__action__Hover_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!action_marvin_interfaces__action__Hover_Goal__init(&msg->goal)) {
    action_marvin_interfaces__action__Hover_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Request__fini(action_marvin_interfaces__action__Hover_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  action_marvin_interfaces__action__Hover_Goal__fini(&msg->goal);
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Request__are_equal(const action_marvin_interfaces__action__Hover_SendGoal_Request * lhs, const action_marvin_interfaces__action__Hover_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!action_marvin_interfaces__action__Hover_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Request__copy(
  const action_marvin_interfaces__action__Hover_SendGoal_Request * input,
  action_marvin_interfaces__action__Hover_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!action_marvin_interfaces__action__Hover_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

action_marvin_interfaces__action__Hover_SendGoal_Request *
action_marvin_interfaces__action__Hover_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Request * msg = (action_marvin_interfaces__action__Hover_SendGoal_Request *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_SendGoal_Request));
  bool success = action_marvin_interfaces__action__Hover_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Request__destroy(action_marvin_interfaces__action__Hover_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__init(action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Request * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_SendGoal_Request *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__fini(action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence *
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * array = (action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__destroy(action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__are_equal(const action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * lhs, const action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence__copy(
  const action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * input,
  action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_SendGoal_Request * data =
      (action_marvin_interfaces__action__Hover_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
action_marvin_interfaces__action__Hover_SendGoal_Response__init(action_marvin_interfaces__action__Hover_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    action_marvin_interfaces__action__Hover_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Response__fini(action_marvin_interfaces__action__Hover_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Response__are_equal(const action_marvin_interfaces__action__Hover_SendGoal_Response * lhs, const action_marvin_interfaces__action__Hover_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Response__copy(
  const action_marvin_interfaces__action__Hover_SendGoal_Response * input,
  action_marvin_interfaces__action__Hover_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

action_marvin_interfaces__action__Hover_SendGoal_Response *
action_marvin_interfaces__action__Hover_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Response * msg = (action_marvin_interfaces__action__Hover_SendGoal_Response *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_SendGoal_Response));
  bool success = action_marvin_interfaces__action__Hover_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Response__destroy(action_marvin_interfaces__action__Hover_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__init(action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Response * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_SendGoal_Response *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__fini(action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence *
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * array = (action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__destroy(action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__are_equal(const action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * lhs, const action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence__copy(
  const action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * input,
  action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_SendGoal_Response * data =
      (action_marvin_interfaces__action__Hover_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
action_marvin_interfaces__action__Hover_GetResult_Request__init(action_marvin_interfaces__action__Hover_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_marvin_interfaces__action__Hover_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
action_marvin_interfaces__action__Hover_GetResult_Request__fini(action_marvin_interfaces__action__Hover_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
action_marvin_interfaces__action__Hover_GetResult_Request__are_equal(const action_marvin_interfaces__action__Hover_GetResult_Request * lhs, const action_marvin_interfaces__action__Hover_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_GetResult_Request__copy(
  const action_marvin_interfaces__action__Hover_GetResult_Request * input,
  action_marvin_interfaces__action__Hover_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

action_marvin_interfaces__action__Hover_GetResult_Request *
action_marvin_interfaces__action__Hover_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Request * msg = (action_marvin_interfaces__action__Hover_GetResult_Request *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_GetResult_Request));
  bool success = action_marvin_interfaces__action__Hover_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_GetResult_Request__destroy(action_marvin_interfaces__action__Hover_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__init(action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Request * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_GetResult_Request *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__fini(action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_GetResult_Request__Sequence *
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * array = (action_marvin_interfaces__action__Hover_GetResult_Request__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__destroy(action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__are_equal(const action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * lhs, const action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_GetResult_Request__Sequence__copy(
  const action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * input,
  action_marvin_interfaces__action__Hover_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_GetResult_Request * data =
      (action_marvin_interfaces__action__Hover_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "action_marvin_interfaces/action/detail/hover__functions.h"

bool
action_marvin_interfaces__action__Hover_GetResult_Response__init(action_marvin_interfaces__action__Hover_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!action_marvin_interfaces__action__Hover_Result__init(&msg->result)) {
    action_marvin_interfaces__action__Hover_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
action_marvin_interfaces__action__Hover_GetResult_Response__fini(action_marvin_interfaces__action__Hover_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  action_marvin_interfaces__action__Hover_Result__fini(&msg->result);
}

bool
action_marvin_interfaces__action__Hover_GetResult_Response__are_equal(const action_marvin_interfaces__action__Hover_GetResult_Response * lhs, const action_marvin_interfaces__action__Hover_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!action_marvin_interfaces__action__Hover_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_GetResult_Response__copy(
  const action_marvin_interfaces__action__Hover_GetResult_Response * input,
  action_marvin_interfaces__action__Hover_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!action_marvin_interfaces__action__Hover_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

action_marvin_interfaces__action__Hover_GetResult_Response *
action_marvin_interfaces__action__Hover_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Response * msg = (action_marvin_interfaces__action__Hover_GetResult_Response *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_GetResult_Response));
  bool success = action_marvin_interfaces__action__Hover_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_GetResult_Response__destroy(action_marvin_interfaces__action__Hover_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__init(action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Response * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_GetResult_Response *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__fini(action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_GetResult_Response__Sequence *
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * array = (action_marvin_interfaces__action__Hover_GetResult_Response__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__destroy(action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__are_equal(const action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * lhs, const action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_GetResult_Response__Sequence__copy(
  const action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * input,
  action_marvin_interfaces__action__Hover_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_GetResult_Response * data =
      (action_marvin_interfaces__action__Hover_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "action_marvin_interfaces/action/detail/hover__functions.h"

bool
action_marvin_interfaces__action__Hover_FeedbackMessage__init(action_marvin_interfaces__action__Hover_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_marvin_interfaces__action__Hover_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!action_marvin_interfaces__action__Hover_Feedback__init(&msg->feedback)) {
    action_marvin_interfaces__action__Hover_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
action_marvin_interfaces__action__Hover_FeedbackMessage__fini(action_marvin_interfaces__action__Hover_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  action_marvin_interfaces__action__Hover_Feedback__fini(&msg->feedback);
}

bool
action_marvin_interfaces__action__Hover_FeedbackMessage__are_equal(const action_marvin_interfaces__action__Hover_FeedbackMessage * lhs, const action_marvin_interfaces__action__Hover_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!action_marvin_interfaces__action__Hover_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_FeedbackMessage__copy(
  const action_marvin_interfaces__action__Hover_FeedbackMessage * input,
  action_marvin_interfaces__action__Hover_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!action_marvin_interfaces__action__Hover_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

action_marvin_interfaces__action__Hover_FeedbackMessage *
action_marvin_interfaces__action__Hover_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_FeedbackMessage * msg = (action_marvin_interfaces__action__Hover_FeedbackMessage *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_marvin_interfaces__action__Hover_FeedbackMessage));
  bool success = action_marvin_interfaces__action__Hover_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_marvin_interfaces__action__Hover_FeedbackMessage__destroy(action_marvin_interfaces__action__Hover_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_marvin_interfaces__action__Hover_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__init(action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_FeedbackMessage * data = NULL;

  if (size) {
    data = (action_marvin_interfaces__action__Hover_FeedbackMessage *)allocator.zero_allocate(size, sizeof(action_marvin_interfaces__action__Hover_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_marvin_interfaces__action__Hover_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_marvin_interfaces__action__Hover_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__fini(action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_marvin_interfaces__action__Hover_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence *
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * array = (action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence *)allocator.allocate(sizeof(action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__destroy(action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__are_equal(const action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * lhs, const action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence__copy(
  const action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * input,
  action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_marvin_interfaces__action__Hover_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_marvin_interfaces__action__Hover_FeedbackMessage * data =
      (action_marvin_interfaces__action__Hover_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_marvin_interfaces__action__Hover_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_marvin_interfaces__action__Hover_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_marvin_interfaces__action__Hover_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
