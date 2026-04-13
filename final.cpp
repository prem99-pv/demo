#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode {
    string content, author;
    int likes;
    TreeNode *left, *right;
    TreeNode(string c, string a, int l) : content(c), author(a), likes(l), left(NULL), right(NULL) {}
};

struct HistoryNode {
    string username, visitTime;
};

struct NotifNode {
    string id, message, type, from;
    bool read;
};

class SocialMediaSystem {
    vector<string> users = {"rahul", "priya", "amit", "sita", "neha", "vikram"};
    vector<list<int>> followAdj;     
    vector<list<int>> friendAdj;     
    stack<HistoryNode> history;      
    queue<NotifNode> notifications;  
    TreeNode* rootPost;              

public:
    SocialMediaSystem() : followAdj(6), friendAdj(6) {
        
        rootPost = new TreeNode("Check out this view! #travel", "rahul", 100);
        rootPost->left = new TreeNode("Amazing photo!", "priya", 10);
        rootPost->right = new TreeNode("Where is this place?", "amit", 5);
    }

   
    void follow(int a, int b) {
        followAdj[a].push_back(b);
        cout << users[a] << " followed " << users[b] << endl;
    }

    void viewFollowing(int a) {
        cout << users[a] << " follows: ";
        for (int id : followAdj[a]) cout << users[id] << " ";
        cout << endl;
    }

    void addFriend(int a, int b) {
        friendAdj[a].push_back(b);
        friendAdj[b].push_back(a);
        cout << users[a] << " and " << users[b] << " are now friends!\n";
    }

    void friendSuggestions(int startUser) {
        cout << "Suggestions for " << users[startUser] << ": ";
        vector<bool> visited(6, false);
        visited[startUser] = true;
        
        for (int friendId : friendAdj[startUser]) visited[friendId] = true;

        for (int friendId : friendAdj[startUser]) {
            for (int fof : friendAdj[friendId]) {
                if (!visited[fof]) {
                    cout << users[fof] << " ";
                    visited[fof] = true;
                }
            }
        }
        cout << endl;
    }

    void displayThread(TreeNode* node) {
        if (!node) return;
        cout << node->author << ": " << node->content << " (" << node->likes << " likes)\n";
        displayThread(node->left);
        displayThread(node->right);
    }

    void showPost() { displayThread(rootPost); }

    void visitProfile(string name) {
        history.push({name, "9:36 PM"});
        cout << "Visited " << name << "'s profile.\n";
    }

    void goBack() {
        if (!history.empty()) {
            cout << "Leaving " << history.top().username << "'s profile.\n";
            history.pop();
        } else cout << "No history to go back.\n";
    }

    void addNotification(string msg, string from) {
        notifications.push({"N001", msg, "Like", from, false});
    }

    void readNotification() {
        if (!notifications.empty()) {
            cout << "Notification: " << notifications.front().message << " from " << notifications.front().from << endl;
            notifications.pop();
        } else cout << "No new notifications.\n";
    }
};

int main() {
    SocialMediaSystem sm;
    int choice;

    do {
        cout << "\n=== SOCIAL MEDIA FRIEND SYSTEM ===\n";
        cout << "1. Follow User (Kirtan -> Priya)\n2. View Following\n3. Add Friend (Kirtan <-> Sita)\n";
        cout << "4. Friend Suggestions (HELLO)\n5. View Comment Thread (HII)\n";
        cout << "6. Visit Profile (GOO)\n7. Go Back\n8. Read Notification (HYYY)\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: sm.follow(0, 1); break;
            case 2: sm.viewFollowing(0); break;
            case 3: sm.addFriend(0, 3); break;
            case 4: sm.friendSuggestions(0); break;
            case 5: sm.showPost(); break;
            case 6: sm.visitProfile("vikram"); break;
            case 7: sm.goBack(); break;
            case 8: sm.readNotification(); break;
        }
    } while (choice != 0);

    return 0;
}