#include <iostream>
#include <fstream>
using namespace std;

class organisation
{
protected:
    string campname, venue, organiser, date;
    int capacity;

public:
    void dispay()
    {
        cout << "Enter camp name: ";
        cin >> campname;

        cout << "Enter venue: ";
        cin >> venue;

        cout << "Enter Organiser: ";
        cin >> organiser;

        cout << "Enter date: ";
        cin >> date;

        cout << "Enter total capacity: ";
        cin >> capacity;
    }
};

class HealthcareCamp : public organisation
{
protected:
    int id[100], age[100];
    string name[100];
    float height[100], weight[100], temperature[100], bp[100];
    int screened[100], referral[100];
    int count = 0;
    long long int cont[100];

public:

    void registerParticipant()
    {
        if (capacity > count && count < 100)
        {
            cout << "\nEnter Participant ID: ";
            cin >> id[count];

            cout << "Enter Name: ";
            cin >> name[count];

            cout << "Enter Age: ";
            cin >> age[count];

            cout << "Enter contact: ";
            cin >> cont[count];

            screened[count] = 0;
            referral[count] = 0;

            count++;

            cout << "Participant Registered Successfully!\n";
        }
        else
        {
            cout << "\nCenter is occupied!\nSee you next time\n";
        }
    }

    void scheduleActivity()
    {
        cout << "\n1. Registration - 9:00 AM";
        cout << "\n2. Screening - 10:00 AM";
        cout << "\n3. Consultation - 11:00 AM\n";
    }

    void recordScreening()
    {
        int n;

        cout << "\nEnter Participant ID: ";
        cin >> n;

        for (int i = 0; i < count; i++)
        {
            if (id[i] == n)
            {
                cout << "Enter Height: ";
                cin >> height[i];

                cout << "Enter Weight: ";
                cin >> weight[i];

                cout << "Enter Temperature: ";
                cin >> temperature[i];

                cout << "Enter BP: ";
                cin >> bp[i];

                screened[i] = 1;

                cout << "Screening Details Recorded!\n";
                return;
            }
        }

        cout << "Participant Not Found!\n";
    }

    void manageQueue()
    {
        cout << "\nParticipants Waiting for Screening:\n";

        for (int i = 0; i < count; i++)
        {
            if (screened[i] == 0)
                cout << id[i] << " - " << name[i] << endl;
        }
    }

    void manageReferral()
    {
        int n;

        cout << "\nEnter Participant ID: ";
        cin >> n;

        for (int i = 0; i < count; i++)
        {
            if (id[i] == n)
            {
                cout << "1. Referral Required";
                cout << "\n2. No Referral\n";

                int choice;
                cin >> choice;

                if (choice == 1)
                    referral[i] = 1;
                else
                    referral[i] = 0;

                cout << "Referral Details Updated!\n";
                return;
            }
        }

        cout << "Participant Not Found!\n";
    }

    void campReport()
    {
        int completed = 0, referred = 0;

        cout << "\n----- HEALTHCARE CAMP REPORT -----\n";

        cout << "Total Participants: " << count << endl;

        for (int i = 0; i < count; i++)
        {
            if (screened[i] == 1)
                completed++;

            if (referral[i] == 1)
                referred++;
        }

        cout << "Screening Completed: " << completed << endl;
        cout << "Screening Pending: " << count - completed << endl;
        cout << "Referral Required: " << referred << endl;
    }
};

class record : public HealthcareCamp
{
public:

    void orgrecord()
    {
        ofstream OutFile("record.txt", ios::app);

        if (OutFile.is_open())
        {
            OutFile << "\n";
            OutFile << campname << " " << venue << " "
                    << organiser << " " << date << " "
                    << capacity;

            OutFile.close();
        }
    }

    void partrecord()
    {
        ofstream OutFile("record.txt", ios::app);

        if (OutFile.is_open())
        {
            for (int i = 0; i < count; i++)
            {
                OutFile << "\n";
                OutFile << id[i] << " "
                        << name[i] << " "
                        << age[i] << " "
                        << cont[i];
            }

            OutFile.close();
        }
    }
};

int main()
{
    record h;
    int choice;

    h.dispay();
    h.orgrecord();

    do
    {
        cout << "\n===== HEALTHCARE CAMP MANAGEMENT =====";
        cout << "\n1. Register Participant";
        cout << "\n2. Schedule Camp Activities";
        cout << "\n3. Record Screening Details";
        cout << "\n4. Manage Queue";
        cout << "\n5. Manage Referrals";
        cout << "\n6. Generate Camp Report";
        cout << "\n7. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                h.registerParticipant();
                h.partrecord();
                break;

            case 2:
                h.scheduleActivity();
                break;

            case 3:
                h.recordScreening();
                break;

            case 4:
                h.manageQueue();
                break;

            case 5:
                h.manageReferral();
                break;

            case 6:
                h.campReport();
                break;

            case 7:
                cout << "Thank You!";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 7);

    return 0;
}
