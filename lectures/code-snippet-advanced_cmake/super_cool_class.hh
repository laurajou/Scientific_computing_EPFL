
struct Vector{

  double val[3];
};

/** This is my super cool class
 *
 */


class SuperCoolClass {

public:

  /** A cool class to test dyoxigen
   *
   * @param dir
   * @return a vector
   */

  Vector getPosition(unsigned int dir){
    return Vector();};

protected:
  
  int var; //!< A super cool variable
  double var1;  /**< A detailed description of a double cool variable. This description, unlike the other ones,
 * will not appear in the protected attributes part of the dyoxigen */
  int var2; //!< Another cool variable
};


class SuperCoolClass2 : public SuperCoolClass {

};
