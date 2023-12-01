#include <cassert>

/// Macro used to create the AI function
# define AI_EXPORT(TYPE)                                \
  extern "C"                                            \
  {                                                     \
    Ai* ai_create (Color color)        \
    {                                                   \
      return new TYPE (color);                          \
    }                                                   \
  }


