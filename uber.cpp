#include "tripMgr.hpp"

int main() {

	//---------------Creating Riders and Drivers--------------------------------
	Rider* naitikRider = new Rider("Naitik", RATING::TWO_STARS);
	Rider* gauravRider = new Rider("Gaurav", RATING::FIVE_STARS);
	//calling base class method without creating instances
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	riderMgr->addRider("naitik", naitikRider);
	riderMgr->addRider("gaurav", gauravRider);

	Driver* yogitaDriver = new Driver("Yogita", RATING::THREE_STARS);
	Driver* riddhiDriver = new Driver("Riddhi", RATING::FOUR_STARS);
	//calling base class without creating instances
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	driverMgr->addDriver("yogita", yogitaDriver);
	driverMgr->addDriver("riddhi", riddhiDriver);

	//These details in turn will be stored in database
	//-------------------------------------------------------------------------
	//calling base class without creating instances
	TripMgr* tripMgr = TripMgr::getTripMgr();


	cout << endl << "Creating Trip for Naitik from location (10,10) to (30,30)" << endl;
	tripMgr->CreateTrip(naitikRider, new Location(10, 10), new Location(30, 30));

	cout << endl << "Creating Trip for Gaurav from location (200,200) to (500,500)" << endl;
	tripMgr->CreateTrip(gauravRider, new Location(200, 200), new Location(500, 500));


	//-------------------Display all the trips created--------------------------
	unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
	for (auto mapVal : tripsMap) {
		(mapVal.second)->displayTripDetails();
	}

	return 0;
}