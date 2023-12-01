#ifndef AI_DUMMY_HH_
# define AI_DUMMY_HH_

# include "ai.hh"
# include "color.hh"
namespace dummy
{
  /*!
  ** \brief Dummy AI
  **
  ** This is an implementation of a dummy AI.
  ** Note that you can put this AI on your own namespace.
  ** You can also put the other classes given in this tarball
  ** in your own namespace(s).
  **
  ** This AI does nothing, it is just an AI implementation example
  */
  class AiDummy : public Ai
  {

  public:

    /*!
    ** \brief Constructor.
    */
    AiDummy (Color color = WHITE);

    /*!
    ** \brief Destructor.
    */
    virtual
    ~AiDummy ();

    /*!
    ** \brief provides the last opponent move to the AI
    **
    */
    virtual void
    last_opponent_move_set (const Move& last_move);

    /*!
    ** \brief name getter
    ** @return Return the AI author name
    */
    virtual const std::string&
    name_get () const;

    /*!
    ** \brief Move getter.
    */
    virtual Move
    move_get ();

  protected:

    /// Last opponent move
      const Move* last_move_;
      Color color_;
      int turn_;
  };
}

#endif // !AI_DUMMY_HH_
