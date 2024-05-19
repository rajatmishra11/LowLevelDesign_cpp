#include <bits/stdc++.h>
using namespace std;

class Message
{
public:
    string text;
    string audio;
    string video;

    Message(string t = "", string a = "", string v = "") : text(t), audio(a), video(v) {}
};

class Status
{
public:
    string text;
    string video;
    string image;

    Status(string t = "", string v = "", string i = "") : text(t), video(v), image(i) {}
};

class User
{
private:
    string name;
    int mobileNumber;
    vector<long long> contacts;
    vector<Message> messages;
    vector<Status> statuses;

public:
    User(string n, int mn) : name(n), mobileNumber(mn) {}

    string getName() const
    {
        return name;
    }

    int getMobileNumber() const
    {
        return mobileNumber;
    }

    void addContact(long long contactNumber)
    {
        contacts.push_back(contactNumber);
    }

    const vector<long long> &getContacts() const
    {
        return contacts;
    }

    void addMessage(const Message &msg)
    {
        messages.push_back(msg);
    }

    const vector<Message> &getMessages() const
    {
        return messages;
    }

    void postStatus(const Status &status)
    {
        statuses.push_back(status);
    }

    const vector<Status> &getStatuses() const
    {
        return statuses;
    }
};

class ChatApp
{
private:
    vector<User> users;

public:
    void addUser(const User &user)
    {
        users.push_back(user);
    }

    User *getUserByMobileNumber(int mobileNumber)
    {
        for (auto &user : users)
        {
            if (user.getMobileNumber() == mobileNumber)
            {
                return &user;
            }
        }
        return nullptr;
    }

    void sendMessage(int senderNumber, int receiverNumber, const string &text, const string &audio = "", const string &video = "")
    {
        User *sender = getUserByMobileNumber(senderNumber);
        User *receiver = getUserByMobileNumber(receiverNumber);

        if (sender && receiver)
        {
            Message message(text, audio, video);
            sender->addMessage(message);
            receiver->addMessage(message);
            cout << "Message sent from " << sender->getName() << " to " << receiver->getName() << endl;
        }
        else
        {
            cout << "Sender or receiver not found." << endl;
        }
    }

    void postUserStatus(int userNumber, const string &text = "", const string &video = "", const string &image = "")
    {
        User *user = getUserByMobileNumber(userNumber);

        if (user)
        {
            Status status(text, video, image);
            user->postStatus(status);
            cout << "Status posted by " << user->getName() << endl;
        }
        else
        {
            cout << "User not found." << endl;
        }
    }

    void displayStatuses(int userNumber)
    {
        User *user = getUserByMobileNumber(userNumber);

        if (user)
        {
            cout << user->getName() << "'s statuses:" << endl;
            for (const auto &status : user->getStatuses())
            {
                cout << "Text: " << status.text << ", Video: " << status.video << ", Image: " << status.image << endl;
            }
        }
        else
        {
            cout << "User not found." << endl;
        }
    }
};

int main()
{
    ChatApp whatsapp;

    User user1("Ashotosh", 1234567890);
    User user2("Bobby", 2345678901);

    whatsapp.addUser(user1);
    whatsapp.addUser(user2);

    user1.addContact(2345678901);
    user2.addContact(1234567890);

    whatsapp.sendMessage(1234567890, 2345678901, "Hello Bobby!");

    whatsapp.postUserStatus(1234567890, "Having a great day!", "VedioSample", "image.jpg");

    whatsapp.displayStatuses(1234567890);
    whatsapp.displayStatuses(2345678901);

    return 0;
}
