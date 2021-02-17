/**
 * @file TrigScintQIEDigis.h
 * @brief class for storing QIE output
 * @author Niramay Gogate, Texas Tech University
 */

#ifndef TRIGSCINT_EVENT_TRIGSCINTQIEDIGIS_H
#define TRIGSCINT_EVENT_TRIGSCINTQIEDIGIS_H

#include "TObject.h" //For ClassDef

namespace trigscint {

  /**
   * @class TrigScintQIEDigis
   * @brief class for storing QIE output
   */
  class TrigScintQIEDigis
  {
  public:

    /**
     * Default constructor
     */
    // TrigScintQIEDigis(){};
    TrigScintQIEDigis() = default;
  
    /**
     * Default destructor
     */
    ~TrigScintQIEDigis() = default;
  
    /**
     * Print ifo about the class
     * @note required by EventDef.h
     */
    void Print(Option_t *option = "") const;

    /**
     * A dummy function
     * @note required by Event/include/Event/EventDef.h
     */
    void Clear(Option_t *option = "");

    /**
     * A dummy operator overloading
     * @note required for declaring std::vector<> in EventDef.h
     */  
    bool operator < ( const TrigScintQIEDigis &rhs ) const
    { return this->chanID_ < rhs.chanID_;}

    /**
     * Get channel ID
     */
    int GetChanID() const{return(chanID_);}

    /**
     * Get ADCs of all time samples
     */
    std::vector<int> GetADC() const{return(adcs_);}

    /**
     * Get tdcs of all time samples
     */
    std::vector<int> GetTDC() const{return(tdcs_);}

    /**
     * Get Cap IDs of all time samples
     */
    std::vector<int> GetCID() const{return(cids_);}

    /**
     * Store the channel ID
     */
    void SetChanID(int chanid) {chanID_ = chanid;}

    /**
     * Store adcs of all time samples
     * @param adc_ array of adcs
     */
    void SetADC(std::vector<int> adc) {adcs_ = adc;}

    /**
     * Store tdcs of all time samples
     * @param tdc_ array of tdcs
     */
    void SetTDC(std::vector<int> tdc) {tdcs_ = tdc;}

    /**
     * Store cids of all time samples
     * @param cid_ array of cids
     */
    void SetCID(std::vector<int> cid) {cids_ = cid;}

  private:
    /// channel ID
    int chanID_;

    /// analog to digital counts
    std::vector<int> adcs_;
    /// Time to Digital counts
    std::vector<int> tdcs_;
    /// capacitor IDs
    std::vector<int> cids_;

    ClassDef(TrigScintQIEDigis,1);
  };
}
#endif
