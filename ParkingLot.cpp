#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User;

class UserManagement
{
public:
    void addUser(int userId)
    {
        // Implementation
    }

    void editUser(int userID, User user)
    {
        // Implementation
    }
};

class FloorManagement
{
public:
    void addFloor(int floornumber)
    {
        // Implementation
    }

    void addSpotFloor(int spotnumber, int floornumber)
    {
        // Implementation
    }
};

class Ticket;

class TicketManagement
{
public:
    Ticket *generateTicket(int userId, string vehicleType, int floorId, int spotId)
    {
        Ticket *ticket = new Ticket(userId, vehicleType, floorId, spotId);
        cout << "Ticket Generated for user " << userId << endl;
        return ticket;
    }
};

class Ticket
{
private:
    int userId;
    int ticketId;
    string vehicleType;
    int allotedfloorid;
    int allotedspotid;

public:
    Ticket(int userId, string vehicleType, int floorid, int spotid)
    {
        this->allotedfloorid = floorid;
        this->allotedspotid = spotid;
        this->userId = userId;
        // Initialize ticketId appropriately
    }
};

class Vehicle
{
protected:
    string vehicleType;
    int vehicleid;

public:
    Vehicle(string vehicleType, int vehicleid)
    {
        this->vehicleid = vehicleid;
        this->vehicleType = vehicleType;
    }

    string getVehicleType()
    {
        return vehicleType;
    }

    int getVehicleId()
    {
        return vehicleid;
    }
};

class User
{
protected:
    int userId;

public:
    User(int userId)
    {
        this->userId = userId;
    }

    bool isUser()
    {
        return (userId != 0);
    }

    int getUserId()
    {
        return userId;
    }
};

class Admin : public User
{
protected:
    int adminId;

public:
    Admin(int adminId) : User(adminId)
    {
        this->adminId = adminId;
    }

    bool isAdmin()
    {
        return (adminId != 0);
    }

    int getAdminId()
    {
        return adminId;
    }
};

class ParkingLot
{
private:
    UserManagement userManagement;
    FloorManagement floorManagement;
    TicketManagement ticketManagement;

public:
    ParkingLot() : userManagement(), floorManagement(), ticketManagement() {}

    UserManagement &getUserManagement()
    {
        return userManagement;
    }

    FloorManagement &getFloorManagement()
    {
        return floorManagement;
    }

    TicketManagement &getTicketManagement()
    {
        return ticketManagement;
    }
};

int main()
{
    ParkingLot pl;
    // Usage of ParkingLot
    return 0;
}
