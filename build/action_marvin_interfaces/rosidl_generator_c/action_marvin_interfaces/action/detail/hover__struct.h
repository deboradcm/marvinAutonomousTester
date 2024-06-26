// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_marvin_interfaces:action/Hover.idl
// generated code does not contain a copyright notice

#ifndef ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_H_
#define ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_Goal
{
  rosidl_runtime_c__String message;
  int16_t initial_x;
  int16_t initial_y;
  int16_t initial_z;
  int16_t final_x;
  int16_t final_y;
  int16_t final_z;
} action_marvin_interfaces__action__Hover_Goal;

// Struct for a sequence of action_marvin_interfaces__action__Hover_Goal.
typedef struct action_marvin_interfaces__action__Hover_Goal__Sequence
{
  action_marvin_interfaces__action__Hover_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_Result
{
  rosidl_runtime_c__String message;
  int16_t x;
  int16_t y;
  int16_t z;
} action_marvin_interfaces__action__Hover_Result;

// Struct for a sequence of action_marvin_interfaces__action__Hover_Result.
typedef struct action_marvin_interfaces__action__Hover_Result__Sequence
{
  action_marvin_interfaces__action__Hover_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_Feedback
{
  rosidl_runtime_c__String message;
  int16_t current_x;
  int16_t current_y;
  int16_t current_z;
} action_marvin_interfaces__action__Hover_Feedback;

// Struct for a sequence of action_marvin_interfaces__action__Hover_Feedback.
typedef struct action_marvin_interfaces__action__Hover_Feedback__Sequence
{
  action_marvin_interfaces__action__Hover_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "action_marvin_interfaces/action/detail/hover__struct.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_marvin_interfaces__action__Hover_Goal goal;
} action_marvin_interfaces__action__Hover_SendGoal_Request;

// Struct for a sequence of action_marvin_interfaces__action__Hover_SendGoal_Request.
typedef struct action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence
{
  action_marvin_interfaces__action__Hover_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} action_marvin_interfaces__action__Hover_SendGoal_Response;

// Struct for a sequence of action_marvin_interfaces__action__Hover_SendGoal_Response.
typedef struct action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence
{
  action_marvin_interfaces__action__Hover_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} action_marvin_interfaces__action__Hover_GetResult_Request;

// Struct for a sequence of action_marvin_interfaces__action__Hover_GetResult_Request.
typedef struct action_marvin_interfaces__action__Hover_GetResult_Request__Sequence
{
  action_marvin_interfaces__action__Hover_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__struct.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_GetResult_Response
{
  int8_t status;
  action_marvin_interfaces__action__Hover_Result result;
} action_marvin_interfaces__action__Hover_GetResult_Response;

// Struct for a sequence of action_marvin_interfaces__action__Hover_GetResult_Response.
typedef struct action_marvin_interfaces__action__Hover_GetResult_Response__Sequence
{
  action_marvin_interfaces__action__Hover_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__struct.h"

/// Struct defined in action/Hover in the package action_marvin_interfaces.
typedef struct action_marvin_interfaces__action__Hover_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_marvin_interfaces__action__Hover_Feedback feedback;
} action_marvin_interfaces__action__Hover_FeedbackMessage;

// Struct for a sequence of action_marvin_interfaces__action__Hover_FeedbackMessage.
typedef struct action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence
{
  action_marvin_interfaces__action__Hover_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_marvin_interfaces__action__Hover_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_H_
