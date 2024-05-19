#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Wall
{
    int WallNumber;
    Wall(wallno)
    {
        this->WallNumber = Wallnumber;
    }
}

class Brick
{
public:
    string comment;
    int brickNo;
    string username;

    // methods->
    string getComment()
    {
        return comment;
    }

    string getUsername()
    {
        return username;
    }
};

class BrickManagement
{
private:
    vector<Brick> bricks; // Vector to store bricks

public:
    void addBrick(const Brick &brick)
    {
        bricks.push_back(brick); // Store the brick in the vector
    }
    void addCommentonBrick()
    {
        // adding comment
    }
    string viewComment(const Brick &brick)
    {
        return brick.getComment();
    }
};

class UserManagement
{
public:
    vector<User> users;

public:
    void addUser(const User &user)
    {
        users.push_back(user);
        // Add user functionality
    }
    void findUser(const User &user)
    {
        // adding user
        return users.find(user);
    }
    int hotuser()
    {
        /// finding hottest user
    }
};

class User
{
public:
    string username;
    string type = "USER";
    User(string username, string type)
    {
        this->username = username;
        this->type = type;
    }
};

class CommentManagement
{
public:
    bool editComment(Brick &brick, const string &comment)
    {
        brick.comment = comment;
        return true; // Indicate successful edit
    }
};

class System
{
private:
    BrickManagement brickmanagement;
    CommentManagement commentmanagement;
    UserManagement usermanagement;

public:
    System() : brickmanagement(), commentmanagement(), usermanagement() {}

    BrickManagement &getBrickManagement()
    {
        return brickmanagement;
    }

    CommentManagement &getCommentManagement()
    {
        return commentmanagement;
    }

    UserManagement &getUserManagement()
    {
        return usermanagement;
    }
};

int main()
{
    // Create System object
    System system;
    Brick brick;
    brick.comment = "Initial comment";
    brick.brickNo = 1;
    brick.username = "User1";

    // Example usage
    system.getBrickManagement().addBrick(brick);

    return 0;
}
