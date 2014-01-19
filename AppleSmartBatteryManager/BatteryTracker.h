//
//  BatteryTracker.h
//  ACPIBatteryManager
//
//  Created by RehabMan on 12/3/13.
//
//

#ifndef __ACPIBatteryManager__BatteryTracker__
#define __ACPIBatteryManager__BatteryTracker__

#define kBatteryTrackerService "rehab_BatteryTracker"

#include "AppleSmartBatteryManager.h"

class EXPORT BatteryTracker : public IOService
{
    OSDeclareDefaultStructors(rehab_BatteryTracker)
    
private:
    OSArray* m_pBatteryList;
    IORecursiveLock* m_pLock;
    
public:
    virtual bool init(OSDictionary* dict);
    virtual bool start(IOService* provider);
    virtual void stop(IOService* provider);
    
    bool addBatteryManager(AppleSmartBatteryManager* pManager);
    bool removeBatteryManager(AppleSmartBatteryManager* pManager);
    void notifyBatteryManagers(bool connected);
    bool anyBatteriesDischarging(AppleSmartBattery* pExcept);
};

#endif /* defined(__ACPIBatteryManager__BatteryTracker__) */