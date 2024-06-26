// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_marvin_interfaces:action/Hover.idl
// generated code does not contain a copyright notice

#ifndef ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_HPP_
#define ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_Goal __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_Goal __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_Goal_
{
  using Type = Hover_Goal_<ContainerAllocator>;

  explicit Hover_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->initial_x = 0;
      this->initial_y = 0;
      this->initial_z = 0;
      this->final_x = 0;
      this->final_y = 0;
      this->final_z = 0;
    }
  }

  explicit Hover_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->initial_x = 0;
      this->initial_y = 0;
      this->initial_z = 0;
      this->final_x = 0;
      this->final_y = 0;
      this->final_z = 0;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _initial_x_type =
    int16_t;
  _initial_x_type initial_x;
  using _initial_y_type =
    int16_t;
  _initial_y_type initial_y;
  using _initial_z_type =
    int16_t;
  _initial_z_type initial_z;
  using _final_x_type =
    int16_t;
  _final_x_type final_x;
  using _final_y_type =
    int16_t;
  _final_y_type final_y;
  using _final_z_type =
    int16_t;
  _final_z_type final_z;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__initial_x(
    const int16_t & _arg)
  {
    this->initial_x = _arg;
    return *this;
  }
  Type & set__initial_y(
    const int16_t & _arg)
  {
    this->initial_y = _arg;
    return *this;
  }
  Type & set__initial_z(
    const int16_t & _arg)
  {
    this->initial_z = _arg;
    return *this;
  }
  Type & set__final_x(
    const int16_t & _arg)
  {
    this->final_x = _arg;
    return *this;
  }
  Type & set__final_y(
    const int16_t & _arg)
  {
    this->final_y = _arg;
    return *this;
  }
  Type & set__final_z(
    const int16_t & _arg)
  {
    this->final_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Goal
    std::shared_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Goal
    std::shared_ptr<action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_Goal_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->initial_x != other.initial_x) {
      return false;
    }
    if (this->initial_y != other.initial_y) {
      return false;
    }
    if (this->initial_z != other.initial_z) {
      return false;
    }
    if (this->final_x != other.final_x) {
      return false;
    }
    if (this->final_y != other.final_y) {
      return false;
    }
    if (this->final_z != other.final_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_Goal_

// alias to use template instance with default allocator
using Hover_Goal =
  action_marvin_interfaces::action::Hover_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces


#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_Result __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_Result __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_Result_
{
  using Type = Hover_Result_<ContainerAllocator>;

  explicit Hover_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }
  }

  explicit Hover_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _x_type =
    int16_t;
  _x_type x;
  using _y_type =
    int16_t;
  _y_type y;
  using _z_type =
    int16_t;
  _z_type z;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__x(
    const int16_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int16_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const int16_t & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Result
    std::shared_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Result
    std::shared_ptr<action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_Result_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_Result_

// alias to use template instance with default allocator
using Hover_Result =
  action_marvin_interfaces::action::Hover_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces


#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_Feedback __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_Feedback_
{
  using Type = Hover_Feedback_<ContainerAllocator>;

  explicit Hover_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->current_x = 0;
      this->current_y = 0;
      this->current_z = 0;
    }
  }

  explicit Hover_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->current_x = 0;
      this->current_y = 0;
      this->current_z = 0;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _current_x_type =
    int16_t;
  _current_x_type current_x;
  using _current_y_type =
    int16_t;
  _current_y_type current_y;
  using _current_z_type =
    int16_t;
  _current_z_type current_z;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__current_x(
    const int16_t & _arg)
  {
    this->current_x = _arg;
    return *this;
  }
  Type & set__current_y(
    const int16_t & _arg)
  {
    this->current_y = _arg;
    return *this;
  }
  Type & set__current_z(
    const int16_t & _arg)
  {
    this->current_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Feedback
    std::shared_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_Feedback
    std::shared_ptr<action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_Feedback_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->current_x != other.current_x) {
      return false;
    }
    if (this->current_y != other.current_y) {
      return false;
    }
    if (this->current_z != other.current_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_Feedback_

// alias to use template instance with default allocator
using Hover_Feedback =
  action_marvin_interfaces::action::Hover_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "action_marvin_interfaces/action/detail/hover__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Request __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_SendGoal_Request_
{
  using Type = Hover_SendGoal_Request_<ContainerAllocator>;

  explicit Hover_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Hover_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const action_marvin_interfaces::action::Hover_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Request
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Request
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_SendGoal_Request_

// alias to use template instance with default allocator
using Hover_SendGoal_Request =
  action_marvin_interfaces::action::Hover_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Response __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_SendGoal_Response_
{
  using Type = Hover_SendGoal_Response_<ContainerAllocator>;

  explicit Hover_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Hover_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Response
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_SendGoal_Response
    std::shared_ptr<action_marvin_interfaces::action::Hover_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_SendGoal_Response_

// alias to use template instance with default allocator
using Hover_SendGoal_Response =
  action_marvin_interfaces::action::Hover_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces

namespace action_marvin_interfaces
{

namespace action
{

struct Hover_SendGoal
{
  using Request = action_marvin_interfaces::action::Hover_SendGoal_Request;
  using Response = action_marvin_interfaces::action::Hover_SendGoal_Response;
};

}  // namespace action

}  // namespace action_marvin_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Request __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_GetResult_Request_
{
  using Type = Hover_GetResult_Request_<ContainerAllocator>;

  explicit Hover_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Hover_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Request
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Request
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_GetResult_Request_

// alias to use template instance with default allocator
using Hover_GetResult_Request =
  action_marvin_interfaces::action::Hover_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Response __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_GetResult_Response_
{
  using Type = Hover_GetResult_Response_<ContainerAllocator>;

  explicit Hover_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Hover_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    action_marvin_interfaces::action::Hover_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const action_marvin_interfaces::action::Hover_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Response
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_GetResult_Response
    std::shared_ptr<action_marvin_interfaces::action::Hover_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_GetResult_Response_

// alias to use template instance with default allocator
using Hover_GetResult_Response =
  action_marvin_interfaces::action::Hover_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces

namespace action_marvin_interfaces
{

namespace action
{

struct Hover_GetResult
{
  using Request = action_marvin_interfaces::action::Hover_GetResult_Request;
  using Response = action_marvin_interfaces::action::Hover_GetResult_Response;
};

}  // namespace action

}  // namespace action_marvin_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_marvin_interfaces__action__Hover_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__action_marvin_interfaces__action__Hover_FeedbackMessage __declspec(deprecated)
#endif

namespace action_marvin_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Hover_FeedbackMessage_
{
  using Type = Hover_FeedbackMessage_<ContainerAllocator>;

  explicit Hover_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Hover_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const action_marvin_interfaces::action::Hover_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_FeedbackMessage
    std::shared_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_marvin_interfaces__action__Hover_FeedbackMessage
    std::shared_ptr<action_marvin_interfaces::action::Hover_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hover_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hover_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hover_FeedbackMessage_

// alias to use template instance with default allocator
using Hover_FeedbackMessage =
  action_marvin_interfaces::action::Hover_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_marvin_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace action_marvin_interfaces
{

namespace action
{

struct Hover
{
  /// The goal message defined in the action definition.
  using Goal = action_marvin_interfaces::action::Hover_Goal;
  /// The result message defined in the action definition.
  using Result = action_marvin_interfaces::action::Hover_Result;
  /// The feedback message defined in the action definition.
  using Feedback = action_marvin_interfaces::action::Hover_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = action_marvin_interfaces::action::Hover_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = action_marvin_interfaces::action::Hover_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = action_marvin_interfaces::action::Hover_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Hover Hover;

}  // namespace action

}  // namespace action_marvin_interfaces

#endif  // ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__STRUCT_HPP_
