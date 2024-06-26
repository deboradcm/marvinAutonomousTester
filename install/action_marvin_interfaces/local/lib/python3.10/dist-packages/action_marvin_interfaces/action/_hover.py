# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_marvin_interfaces:action/Hover.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Hover_Goal(type):
    """Metaclass of message 'Hover_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_Goal(metaclass=Metaclass_Hover_Goal):
    """Message class 'Hover_Goal'."""

    __slots__ = [
        '_message',
        '_initial_x',
        '_initial_y',
        '_initial_z',
        '_final_x',
        '_final_y',
        '_final_z',
    ]

    _fields_and_field_types = {
        'message': 'string',
        'initial_x': 'int16',
        'initial_y': 'int16',
        'initial_z': 'int16',
        'final_x': 'int16',
        'final_y': 'int16',
        'final_z': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())
        self.initial_x = kwargs.get('initial_x', int())
        self.initial_y = kwargs.get('initial_y', int())
        self.initial_z = kwargs.get('initial_z', int())
        self.final_x = kwargs.get('final_x', int())
        self.final_y = kwargs.get('final_y', int())
        self.final_z = kwargs.get('final_z', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.message != other.message:
            return False
        if self.initial_x != other.initial_x:
            return False
        if self.initial_y != other.initial_y:
            return False
        if self.initial_z != other.initial_z:
            return False
        if self.final_x != other.final_x:
            return False
        if self.final_y != other.final_y:
            return False
        if self.final_z != other.final_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def initial_x(self):
        """Message field 'initial_x'."""
        return self._initial_x

    @initial_x.setter
    def initial_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'initial_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'initial_x' field must be an integer in [-32768, 32767]"
        self._initial_x = value

    @builtins.property
    def initial_y(self):
        """Message field 'initial_y'."""
        return self._initial_y

    @initial_y.setter
    def initial_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'initial_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'initial_y' field must be an integer in [-32768, 32767]"
        self._initial_y = value

    @builtins.property
    def initial_z(self):
        """Message field 'initial_z'."""
        return self._initial_z

    @initial_z.setter
    def initial_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'initial_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'initial_z' field must be an integer in [-32768, 32767]"
        self._initial_z = value

    @builtins.property
    def final_x(self):
        """Message field 'final_x'."""
        return self._final_x

    @final_x.setter
    def final_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'final_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'final_x' field must be an integer in [-32768, 32767]"
        self._final_x = value

    @builtins.property
    def final_y(self):
        """Message field 'final_y'."""
        return self._final_y

    @final_y.setter
    def final_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'final_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'final_y' field must be an integer in [-32768, 32767]"
        self._final_y = value

    @builtins.property
    def final_z(self):
        """Message field 'final_z'."""
        return self._final_z

    @final_z.setter
    def final_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'final_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'final_z' field must be an integer in [-32768, 32767]"
        self._final_z = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_Result(type):
    """Metaclass of message 'Hover_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_Result(metaclass=Metaclass_Hover_Result):
    """Message class 'Hover_Result'."""

    __slots__ = [
        '_message',
        '_x',
        '_y',
        '_z',
    ]

    _fields_and_field_types = {
        'message': 'string',
        'x': 'int16',
        'y': 'int16',
        'z': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())
        self.x = kwargs.get('x', int())
        self.y = kwargs.get('y', int())
        self.z = kwargs.get('z', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.message != other.message:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'x' field must be an integer in [-32768, 32767]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'y' field must be an integer in [-32768, 32767]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'z' field must be an integer in [-32768, 32767]"
        self._z = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_Feedback(type):
    """Metaclass of message 'Hover_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_Feedback(metaclass=Metaclass_Hover_Feedback):
    """Message class 'Hover_Feedback'."""

    __slots__ = [
        '_message',
        '_current_x',
        '_current_y',
        '_current_z',
    ]

    _fields_and_field_types = {
        'message': 'string',
        'current_x': 'int16',
        'current_y': 'int16',
        'current_z': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())
        self.current_x = kwargs.get('current_x', int())
        self.current_y = kwargs.get('current_y', int())
        self.current_z = kwargs.get('current_z', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.message != other.message:
            return False
        if self.current_x != other.current_x:
            return False
        if self.current_y != other.current_y:
            return False
        if self.current_z != other.current_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def current_x(self):
        """Message field 'current_x'."""
        return self._current_x

    @current_x.setter
    def current_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_x' field must be an integer in [-32768, 32767]"
        self._current_x = value

    @builtins.property
    def current_y(self):
        """Message field 'current_y'."""
        return self._current_y

    @current_y.setter
    def current_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_y' field must be an integer in [-32768, 32767]"
        self._current_y = value

    @builtins.property
    def current_z(self):
        """Message field 'current_z'."""
        return self._current_z

    @current_z.setter
    def current_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_z' field must be an integer in [-32768, 32767]"
        self._current_z = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_SendGoal_Request(type):
    """Metaclass of message 'Hover_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__send_goal__request

            from action_marvin_interfaces.action import Hover
            if Hover.Goal.__class__._TYPE_SUPPORT is None:
                Hover.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_SendGoal_Request(metaclass=Metaclass_Hover_SendGoal_Request):
    """Message class 'Hover_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'action_marvin_interfaces/Hover_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_marvin_interfaces', 'action'], 'Hover_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from action_marvin_interfaces.action._hover import Hover_Goal
        self.goal = kwargs.get('goal', Hover_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from action_marvin_interfaces.action._hover import Hover_Goal
            assert \
                isinstance(value, Hover_Goal), \
                "The 'goal' field must be a sub message of type 'Hover_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_SendGoal_Response(type):
    """Metaclass of message 'Hover_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_SendGoal_Response(metaclass=Metaclass_Hover_SendGoal_Response):
    """Message class 'Hover_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_Hover_SendGoal(type):
    """Metaclass of service 'Hover_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hover__send_goal

            from action_marvin_interfaces.action import _hover
            if _hover.Metaclass_Hover_SendGoal_Request._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_SendGoal_Request.__import_type_support__()
            if _hover.Metaclass_Hover_SendGoal_Response._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_SendGoal_Response.__import_type_support__()


class Hover_SendGoal(metaclass=Metaclass_Hover_SendGoal):
    from action_marvin_interfaces.action._hover import Hover_SendGoal_Request as Request
    from action_marvin_interfaces.action._hover import Hover_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_GetResult_Request(type):
    """Metaclass of message 'Hover_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_GetResult_Request(metaclass=Metaclass_Hover_GetResult_Request):
    """Message class 'Hover_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_GetResult_Response(type):
    """Metaclass of message 'Hover_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__get_result__response

            from action_marvin_interfaces.action import Hover
            if Hover.Result.__class__._TYPE_SUPPORT is None:
                Hover.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_GetResult_Response(metaclass=Metaclass_Hover_GetResult_Response):
    """Message class 'Hover_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'action_marvin_interfaces/Hover_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_marvin_interfaces', 'action'], 'Hover_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from action_marvin_interfaces.action._hover import Hover_Result
        self.result = kwargs.get('result', Hover_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from action_marvin_interfaces.action._hover import Hover_Result
            assert \
                isinstance(value, Hover_Result), \
                "The 'result' field must be a sub message of type 'Hover_Result'"
        self._result = value


class Metaclass_Hover_GetResult(type):
    """Metaclass of service 'Hover_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hover__get_result

            from action_marvin_interfaces.action import _hover
            if _hover.Metaclass_Hover_GetResult_Request._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_GetResult_Request.__import_type_support__()
            if _hover.Metaclass_Hover_GetResult_Response._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_GetResult_Response.__import_type_support__()


class Hover_GetResult(metaclass=Metaclass_Hover_GetResult):
    from action_marvin_interfaces.action._hover import Hover_GetResult_Request as Request
    from action_marvin_interfaces.action._hover import Hover_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Hover_FeedbackMessage(type):
    """Metaclass of message 'Hover_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hover__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hover__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hover__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__hover__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hover__feedback_message

            from action_marvin_interfaces.action import Hover
            if Hover.Feedback.__class__._TYPE_SUPPORT is None:
                Hover.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hover_FeedbackMessage(metaclass=Metaclass_Hover_FeedbackMessage):
    """Message class 'Hover_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'action_marvin_interfaces/Hover_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_marvin_interfaces', 'action'], 'Hover_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from action_marvin_interfaces.action._hover import Hover_Feedback
        self.feedback = kwargs.get('feedback', Hover_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from action_marvin_interfaces.action._hover import Hover_Feedback
            assert \
                isinstance(value, Hover_Feedback), \
                "The 'feedback' field must be a sub message of type 'Hover_Feedback'"
        self._feedback = value


class Metaclass_Hover(type):
    """Metaclass of action 'Hover'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_marvin_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_marvin_interfaces.action.Hover')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__hover

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from action_marvin_interfaces.action import _hover
            if _hover.Metaclass_Hover_SendGoal._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_SendGoal.__import_type_support__()
            if _hover.Metaclass_Hover_GetResult._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_GetResult.__import_type_support__()
            if _hover.Metaclass_Hover_FeedbackMessage._TYPE_SUPPORT is None:
                _hover.Metaclass_Hover_FeedbackMessage.__import_type_support__()


class Hover(metaclass=Metaclass_Hover):

    # The goal message defined in the action definition.
    from action_marvin_interfaces.action._hover import Hover_Goal as Goal
    # The result message defined in the action definition.
    from action_marvin_interfaces.action._hover import Hover_Result as Result
    # The feedback message defined in the action definition.
    from action_marvin_interfaces.action._hover import Hover_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from action_marvin_interfaces.action._hover import Hover_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from action_marvin_interfaces.action._hover import Hover_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from action_marvin_interfaces.action._hover import Hover_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
