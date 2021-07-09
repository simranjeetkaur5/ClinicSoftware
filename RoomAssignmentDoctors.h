#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class RoomAssignmentDoctors
{
		private:
			int mappingId;
			int doctorId;
			int roomId;
            bool ActiveState;
			fstream fRoom;
		public:
			void roomMenu();
			int get_mapping_id(){return mappingId; }
};

void RoomAssignmentDoctors::roomMenu()
{
	cout<<"Room Assignments";
}