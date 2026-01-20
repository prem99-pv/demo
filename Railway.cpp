#include <iostream>
using namespace std;

class Train
{
private:
    int trainnum;
    char trainname[50];
    char trainsource[50];
    char traindesti[50];
    char traintime[10];

public:
    void addtrain()
    {
        cout << "Enter train Number: ";
        cin >> trainnum;

        cout << "Enter train Name: ";
        cin.getline(trainname, 100);
        ;

        cout << "Enter train Source: ";
        cin.getline(trainsource, 100);

        cout << "Enter train Destiny: ";
        cin.getline(traindesti, 100);

        cout << "Enter train Time: ";
        cin.getline(traintime, 100);
    }

    void showdetail()
    {
        cout << "\nTrain Number : " << trainnum;
        cout << "\nTrain Name   : " << trainname;
        cout << "\nSource       : " << trainsource;
        cout << "\nDestination  : " << traindesti;
        cout << "\nTrain Time   : " << traintime << endl;
    }

    int getTrainNo()
    {
        return trainnum;
    }
};

int main()
{
    Train t1[10];
    int count = 0;
    int choice = 0, searchNo;
    bool found;

    while (choice != 4)
    {
        cout << "\n\n===== Train Record Menu =====";
        cout << "\n1. Add Train Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Search by Train Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 10)
            {
                t1[count].addtrain();
                count++;
            }
            else
            {
                cout << "\nRecord limit reached!";
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "\nNo records available!";
            }
            else
            {
                for (int i = 0; i < count; i++)
                    t1[i].showdetail();
            }
            break;

        case 3:
            cout << "\nEnter Train Number to search: ";
            cin >> searchNo;
            found = false;

            for (int i = 0; i < count; i++)
            {
                if (t1[i].getTrainNo() == searchNo)
                {
                    t1[i].showdetail();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nTrain not found!";
            break;

        case 4:
            cout << "\nExiting program...";
            break;

        default:
            cout << "\nInvalid choice!";
        }
    }

    return 0;
}