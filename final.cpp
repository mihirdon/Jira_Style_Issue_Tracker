#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
<<<<<<< HEAD
=======
#include<bits/stdc++.h>
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
#include<cmath>
#include<algorithm>
#include<time.h>

using namespace std;

<<<<<<< HEAD
//Defualt Task
enum class IssueType { UserStory , Task, Build, Test, Debug, Documentation };

//Default Developer
enum class UserRole { Developer, ProjectLead, ProjectOwner };

//Default VeryLow
enum class Priority { VeryLow, Low, Medium, High, VeryHigh};

//Default Open
=======
enum class IssueType { UserStory , Task, Build, Test, Debug, Documentation };

enum class UserRole { Developer, ProjectLead, ProjectOwner };

enum class Priority { VeryLow, Low, Medium, High, VeryHigh};

>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
enum class IssueStatus { Open, InProgress, Done, Overdue};

string ITtoString(IssueType it) {
	switch(it) {
		case IssueType::UserStory: return "UserStory";
		case IssueType::Task: return "Task";
		case IssueType::Build: return "Build";
		case IssueType::Test: return "Test";
		case IssueType::Debug: return "Debug";
		case IssueType::Documentation: return "Documentation";
<<<<<<< HEAD
		default: return "None";
=======
		default: return "No";
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
	}
}


IssueType stringToIT(string s) {
        if (s == "UserStory") return IssueType::UserStory;
	else if(s == "Task") return IssueType::Task;
	else if(s == "Build") return IssueType::Build;
	else if(s == "Test") return IssueType::Test;
	else if(s == "Debug") return IssueType::Debug;
	else return IssueType::Documentation;
}


string URtoString(UserRole ur) {
        switch(ur) {
                case UserRole::Developer: return "Developer";
                case UserRole::ProjectLead: return "ProjectLead";
                case UserRole::ProjectOwner: return "ProjectOwner";
<<<<<<< HEAD
                default: return "None";
=======
                default: return "No";
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
        }
}

UserRole stringToUR(string s) {
        if (s == "Developer") return UserRole::Developer;
        else if(s == "ProjectLead") return UserRole::ProjectLead;
        else return UserRole::ProjectOwner;
}


string PtoString(Priority p) {
        switch(p) {
                case Priority::VeryLow: return "VeryLow";
                case Priority::Low: return "Low";
                case Priority::Medium: return "Medium";
		case Priority::High: return "High";
                case Priority::VeryHigh: return "VeryHigh";
<<<<<<< HEAD
                default: return "None";
=======
                default: return "No";
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
        }
}

Priority stringToP(string s) {
        if (s == "VeryLow") return Priority::VeryLow;
        else if(s == "Low") return Priority::Low;
        else if(s == "Medium") return Priority::Medium;
        else if(s == "High") return Priority::High;
        else return Priority::VeryHigh;
}


string IStoString(IssueStatus is) {
        switch(is) {
                case IssueStatus::Open: return "Open";
                case IssueStatus::InProgress: return "InProgress";
                case IssueStatus::Done: return "Done";
                case IssueStatus::Overdue: return "Overdue";
<<<<<<< HEAD
                default: return "None";
=======
                default: return "No";
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
        }
}

IssueStatus stringToIS(string s) {
        if (s == "Open") return IssueStatus::Open;
        else if(s == "InProgress") return IssueStatus::InProgress;
        else if(s == "Done") return IssueStatus::Done;
        else return IssueStatus::Overdue;
}

<<<<<<< HEAD
//Update: its almost midnight and to help with dueDate I removed: c == ' ' 
bool isInvisible(unsigned char c) {
    return (c == ' ' || c == '\n' || c == '\r' ||
        c == '\t' || c == '\v' || c == '\f');
}

string ifEmpty(string s) {
    return (s == "") ? "_" : s;
}

string revIfEmpty(string s) {
    return (s == "_") ? "" : s;
}
=======


>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f

	
class Issue {
	private:
		string title;
		string desc;
		string assignee;
<<<<<<< HEAD
		static int count;
=======
		static int count = 0;
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
		int uniqueId;
		IssueType type;
		string reporter;
		time_t dateCreated;
		time_t dueDate;
		double completionPerc;
		vector<string> comments;
		Priority pr;
<<<<<<< HEAD
    IssueStatus is;
	public:	

		Issue(string i_reporter, string i_title) {
			title = i_title;
			assignee = "";
			time(&dateCreated);
      dueDate = 0;
			uniqueId = count++;
			reporter = i_reporter;
      type = IssueType::Task;
      pr = Priority::VeryLow;
      is = IssueStatus::Open;
      completionPerc = 0;
=======
	public:	

		Issue(string i_title, time_t i_dueDate, string i_reporter) {
			title = i_title;
			assignee = "";
			dueDate = i_dueDate;
			time(&dateCreated);
			uniqueId = count++;
			reporter = i_reporter;
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
		
		}


		Issue(string entireLine) {
			vector<string> arr;
<<<<<<< HEAD
      char *cpy = &entireLine[0];
      string s_pipe = "|";
      const char *pipe = s_pipe.c_str();
      
			char *token = strtok(cpy, pipe);
			
			while (token != NULL) {
				arr.push_back(token);
				token = strtok(NULL, pipe);
			}

			uniqueId = stoi(arr[1]);
      count++;
			title = revIfEmpty(arr[2]);
			reporter = revIfEmpty(arr[3]);
			assignee = revIfEmpty(arr[4]);
=======
			char *token = strtok(entireLine, "|");
			
			while (token != NULL) {
				arr.push_back(token);
				token = strtok(NULL, "|");
			}

			uniqueId = stoi(arr[1]);
			title = arr[2];
			reporter = arr[3];
			assignee = arr[4];
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
			dateCreated = static_cast<time_t>(stoll(arr[5], NULL, 0));
			dueDate = static_cast<time_t>(stoll(arr[6], NULL, 0));
			type = stringToIT(arr[7]);
			pr = stringToP(arr[8]);
<<<<<<< HEAD
      is = stringToIS(arr[9]);
			completionPerc = stoi(arr[10]);
			desc = revIfEmpty(arr[11]);

      if (arr[12] != "_") {
    			for (int i = 12; i < arr.size(); i++) {
    				comments.push_back(arr[i]);		
    			}
      }
		}


		Issue(string i_title, string i_assignee, string i_desc, IssueType i_type, IssueStatus i_is,
			string i_reporter, time_t i_dateCreated, time_t i_dueDate, double i_complete, Priority i_pr, vector<string> collab) {
      if (find(collab.begin(), collab.end(), i_assignee) == collab.end()) {
          throw invalid_argument("Assignee must be a collaborator in the project");
      }
      uniqueId = count++;
=======
			completionPerc = stoi(arr[9]);
			desc = arr[10];
				
			for (int i = 11; i < arr.size(); i++) {
				comments.push_back(arr[i]);		
			}
		}


		Issue(string i_title, string i_assignee, string i_desc, IssueType i_type, string i_type, 
			string i_reporter, time_t i_dateCreated, time_t i_dueDate, double i_complete, Priority i_pr) {
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
			title = i_title;
			assignee = i_assignee;
			desc = i_desc;
			type = i_type;
			reporter = i_reporter;
			dateCreated = i_dateCreated;
			dueDate = i_dueDate;
			completionPerc = i_complete;
			pr = i_pr;
<<<<<<< HEAD
      is = i_is;
=======
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
		} 
		




		bool hasPermission(string userName, UserRole role) {
<<<<<<< HEAD
			if(role != UserRole::Developer) return true;
			else if(userName == assignee) return true; // Only the assigned user can edit it
			else {
          cout << "You do not have the permission to edit this element" << endl;
          return false;
        }
		}

		void setTitle(string userName, UserRole role, string s) {
			  if(hasPermission(userName, role)) {
				    title = s;
			  }
		}

		void setDescription(string userName, UserRole role, string s) {
        if(hasPermission(userName, role)) {
				    desc = s;
        }
    }

		void setReporter(string userName, UserRole role, string s) {
        if(hasPermission(userName, role)) {
				    reporter = s;
        }
    }

		void setAssignee(string userName, UserRole role, string s) {
        if(hasPermission(userName, role)) {
            assignee = s;
        }
     }

		void addComment(string s) {
        comments.push_back(s); //anyone should be able to comment!!
     }

		void removeComment(int index) {
			  comments.erase(comments.begin() + (index - 1));
		}

		void displayComments() {		
			  for(int i = 0; i < comments.size(); i++) {
				    cout<<i+1<<": "<<comments[i]<<endl;
			  }
		}	

		void setType(string userName, UserRole role, IssueType s) {
        if(hasPermission(userName, role)) {
				    type = s;
        }
    }

		void setPriority(string userName, UserRole role, Priority p) {
			  if(hasPermission(userName, role)) {
            pr = p;
        }
=======
			if(role != userRole::Developer) return true;
			else if(userName == assignee) return true; // Only the assigned user can edit it
			else {return false;}
		}

		void setTitle(string userName, UserRole role, string s) {
			if(hasPermission(userName, role)) {
				title = s;
			}
		}

		void setDescription(string userName, UserRole role, string s) {
                        if(hasPermission(userName, role)) {
				description = s;
                        }
                }

		void setReporter(string userName, UserRole role, string s) {
                        if(hasPermission(userName, role)) {
				reporter = s;
                        }
                }

		void setAssignee(string userName, UserRole role, string s) {
                        if(hasPermission(userName, role)) {
                                assignee = s;
                        }
                }

		void addComment(string s) {
                	comments.push_back(s); //anyone should be able to comment!!
                }

		void removeComment(int index) {
			comments.erase(comments.begin() + (index - 1));
		}

		void displayComments() {		
			for(int i = 0; i < comments.size(); i++) {
				cout<<i+1<<": "<<comments[i]<<endl;
			}
		}	

		void setType(string userName, UserRole role, IssueType s) {
                        if(hasPermission(userName, role)) {
				type = s;
                        }
                }

		void setPriority(string userName, UserRole role, Priority p) {
			if(hasPermission(userName, role)) {
                                 pr = p;
                         }
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
		}

		//TODO: finish set completion percentage method!!, or update by time
		
		void setDueDate(string userName, UserRole role, time_t d) {
			if(hasPermission(userName, role)) {
<<<<<<< HEAD
            dueDate = d;
      }

		}

    void setIssueStatus(string userName, UserRole role, IssueStatus s) {
			  if(hasPermission(userName, role)) {
            is = s;
        }
		}
    



		friend ostream& operator<<(ostream & o, const Issue& i) {
      time_t t = i.dateCreated;
      time_t *tp = &t;

      time_t t2 = i.dueDate;
      time_t *t2p = &t2;

      string due = (i.dueDate == 0) ? "not set" : ctime(t2p);
      
      o << "Issue " << i.uniqueId << ": " << i.title << endl;
			o << "Reporter: " << i.reporter << " Assignee: " << i.assignee << endl;
			o << "Date Created: " << ctime(tp) << " Due Date: " << due << endl;
			o << "Issue Type: " << ITtoString(i.type) << " Priority: " << PtoString(i.pr) << " Issue Status: " << IStoString(i.is) << endl;
			o << "Completion Percentage: " << i.completionPerc << "%" << endl;
			o << "Description: " << i.desc << endl;
			o << "Comments: " << endl;

			for (int j = 0; j < i.comments.size(); j++) {
				o << j+1 << ") " << i.comments[j] << endl;
			}
	
			o << endl;
      return o;
    }	

		string issueToString() {
			string s;
      
      

			s += "I|";
			s += to_string(uniqueId) + "|";
			s += ifEmpty(title) + "|";
			s += ifEmpty(reporter) + "|";
			s += ifEmpty(assignee) + "|";
			s += to_string(dateCreated) + "|";
			s += to_string(dueDate) + "|";
			s += ITtoString(type) + "|";
			s += PtoString(pr) + "|";
      s += IStoString(is) + "|";
			s += to_string(completionPerc) + "|";
			s += ifEmpty(desc) + "|";

      if (comments.size() == 0) {
          s += "_|";
      }
      
			for (int i = 0; i < comments.size(); i++) {
				s += ifEmpty(comments[i]) + "|";
=======
                                  dueDate = d;
                          }

		}



		friend ostream& operator<<(ostream & o, const Issue& i) {
                        o << "Issue " << uniqueId << ": " << title << endl;
			o << "Reporter: " << reporter << " Assignee: " << assignee << endl;
			o << "Date Created: " << ctime(dateCreated) << " Due Date: " << ctime(dueDate) << endl;
			o << "Issue Type: " << ITtoString(type) << " Priority: " << PtoString(pr) << endl;
			o << "Completion Percentage: " << completionPerc << "%" << endl;
			o << "Description: " << desc << endl;
			o << "Comments: " << endl;

			for (int i = 0; i < comments.size(); i++) {
				o << i << ") " << comments[i] << endl;
			}
	
			o << endl;
                        return o;
                }	

		string issueToString() {
			string s;

			s += "I|";
			s += uniqueId + "|";
			s += title + "|";
			s += reporter + "|";
			s += assignee + "|";
			s += dateCreated + "|";
			s += dueDate + "|";
			s += ITtoString(type) + "|";
			s += PtoString(pr) + "|";
			s += to_string(completionPerc) + "|";
			s += desc + "|";

			for (int i = 0; i < comments.size(); i++) {
				s += comments[i] + "|";
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
			}

			s += "\n";

			return s;
		}



<<<<<<< HEAD
		void mainMenu(string userName, UserRole role, vector<string> collab) {
			while (1) {
        cout << endl << endl << endl << endl;
				cout << *this << endl;
				
				cout << "(1) set title" << endl; //TITLE
 	      cout << "(2) set due date" << endl;
        cout << "(3) set priority" << endl; //ENUM
        cout << "(4) set assignee" << endl; //PERSON
        cout << "(5) set reporter" << endl; //COPY from PERSOn
        cout << "(6) set description" << endl; //COPY from TITLE
        cout << "(7) set type" << endl; //COPY from ENUM
				cout << "(8) display comments" << endl; //DISPLAY
        cout << "(9) remove comment" << endl; //CALL DISPLAY then run remove (rememer to add quit)
        cout << "(10) add comment" << endl; //CALL DISPLAY then add comment (remember to add quit)
        cout << "(11) set issue status" << endl; //Copy from ENUM
        cout << "(12) exit from issue editor" << endl;
=======
		void mainMenu(string userName, UserRole role) {
			while (1) {
				cout << this << endl;
				
				cout << "(1) set title" << endl;
 	                        cout << "(2) set due date" << endl;
        	                cout << "(3) set priority" << endl;
                	        cout << "(4) set assignee" << endl;
                       		cout << "(5) set reporter" << endl;
                     		cout << "(6) set description" << endl;
                        	cout << "(7) set type" << endl;
				cout << "(8) display comments" << endl;
                        	cout << "(9) remove comment" << endl;
                        	cout << "(10) add comment" << endl;
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
				cout << endl;
	
				int cmd;
				cout << "Please input one of the above commands:" << endl;
				cin >> cmd;
			
<<<<<<< HEAD
				switch(cmd) {
					case 1: 
            {
						char s[120];
						cout << "Please Input a New Title:" << endl;
            cin.ignore();
						cin.getline(s, 120);
						string str(s);

						setTitle(userName, role, str);
						break;
            }
					case 2: 
          {
            int c = 0;
            while (1) {
                char s[120];
                struct tm *time_tm, *cur_tm; 
                
                cout << "Please Input the new Due Date" << endl;
                cout << "Please input it in the format: %m-%d-%Y %H:%M:%S" << endl;
                
                if (c == 0) {
                    cin.ignore();
                }
                cin.getline(s, 120);
                string str(s);

                time_t curTime;
                curTime = time(NULL);
                time_tm = localtime(&dueDate);
                
                strptime(str.c_str(), "%m-%d-%Y %H:%M:%S", time_tm);

                time_t temp = dueDate;
                
                setDueDate(userName, role,  mktime(time_tm));
                
                if (dueDate == 0) {
                    cout << "Invalid Input! Please enter in the format listed above" << endl;
                    cout << endl;
                }
                else if (difftime(dueDate, curTime) <= 0) {
                    cout << "Please try again! You have listed an invalid date!" << endl;
                    dueDate = temp; //Didnt use setter here because we don't need to perform the checks we would normally
                }
                else {break;}
              }
						break;
            }
					case 3:
          {
                int c = 0;
                while (1) {
                    char s[120];
						        cout << "Please Input a New Priority:" << endl;
                    cout << "Options: VeryLow, Low, Medium, High, VeryHigh" << endl;

                    if (c == 0) {
                        cin.ignore();
                    }
						        cin.getline(s, 120);
						        string str(s);
                    str.erase(std::remove_if(str.begin(), str.end(), isInvisible), str.end());

                    if (str == "VeryLow" || str == "Low" || str == "Medium" || str == "High"|| str == "VeryHigh") {
                        setPriority(userName, role, stringToP(str));
                        break;
                    }
                    else {
                        cout << "Please input one of the options listed above!" << endl;
                        c++;
                    }
                }
              break;
          }
          case 4: 
          {
            int c = 0;
            while (1) {
						    char s[120];
						    cout << "Please Input a New Assignee:" << endl;
                if (c == 0) {
                        cin.ignore();
                }
						    cin.getline(s, 120);
						    string str(s);
                str.erase(std::remove_if(str.begin(), str.end(), isInvisible), str.end());

						    if (find(collab.begin(), collab.end(), str) != collab.end()) { 
                    setAssignee(userName, role, str);
                    break;
                }
                else {
                        cout << "Assignee must be a collaborator in the project" << endl;
                        c++;
                }
            }
            break;
          }
          case 5:
          {
            int c = 0;
            while (1) {
						    char s[120];
						    cout << "Please Input a New Reporter:" << endl;
                if (c == 0) {
                        cin.ignore();
                }
						    cin.getline(s, 120);
						    string str(s);
                str.erase(std::remove_if(str.begin(), str.end(), isInvisible), str.end());

						    if (find(collab.begin(), collab.end(), str) != collab.end()) { 
                    setReporter(userName, role, str);
                    break;
                }
                else {
                        cout << "Reporter must be a collaborator in the project" << endl;
                        c++;
                }
            }
            break;
          }
          case 6:
          {
						char s[9001];
						cout << "Please Input a New Description:" << endl;
            cin.ignore();
						cin.getline(s, 9001);
						string str(s);

						setDescription(userName, role, str);
						break;
          }
          case 7:
          {
                int c = 0;
                while (1) {
                    char s[120];
						        cout << "Please Input a New Issue Type:" << endl;
                    cout << "Options: UserStory, Task, Build, Test, Debug, Documentation" << endl;

                    if (c == 0) {
                        cin.ignore();
                    }
						        cin.getline(s, 120);
						        string str(s);
                    str.erase(std::remove_if(str.begin(), str.end(), isInvisible), str.end());

                    if (str == "UserStory" || str == "Task" || str == "Test" || str == "Debug"
                         || str == "Build" || str == "Documentation") {
                        setType(userName, role, stringToIT(str));
                        break;
                    }
                    else {
                        cout << "Please input one of the options listed above!" << endl;
                        c++;
                    }
                }
              break;
          }
          case 8:
              cout << "Comments: " << endl;

			        for (int j = 0; j < comments.size(); j++) {
				          cout << j+1 << ") " << comments[j] << endl;
			        }
	
			        cout << endl;
              break;
          case 9:
          { 
              while(1) { 
                cout << "Comments: " << endl;
  
  			        for (int j = 0; j < comments.size(); j++) {
  				          cout << j+1 << ") " << comments[j] << endl;
  			        }
  
                int resp;
  			        cout << endl;
                cout << "Please give the index of the comment you wish to remove or -1 to return to Issue menu!" << endl;
                cin >> resp;
  
                if (resp == -1) {
                  break;
                }

                if (resp >= 1 && resp <= comments.size()) {
                  removeComment(resp);
                  break;
                }
                else {
                  cout << "Please enter a valid index!" << endl;
                }
              }
              break;
          }
          case 10:
          { 
              cout << "Comments: " << endl;

              for (int j = 0; j < comments.size(); j++) {
                  cout << j+1 << ") " << comments[j] << endl;
              }

              char s[9001];
              cout << "Please Input a New Comment:" << endl;
              cin.ignore();
              cin.getline(s, 9001);
              string str(s);
              
              addComment(str);
              break;
          }
          case 11:
          {
                int c = 0;
                while (1) {
                    char s[120];
						        cout << "Please Input a New Issue Status:" << endl;
                    cout << "Options: Open, InProgress, Done, Overdue" << endl;

                    if (c == 0) {
                        cin.ignore();
                    }
						        cin.getline(s, 120);
						        string str(s);
                    str.erase(std::remove_if(str.begin(), str.end(), isInvisible), str.end());

                    if (str == "Open" || str == "InProgress" || str == "Done" || str == "Overdue") {
                        setIssueStatus(userName, role, stringToIS(str));
                        break;
                    }
                    else {
                        cout << "Please input one of the options listed above!" << endl;
                        c++;
                    }
                }
              break;
				  }
          case 12:
              return;
          default:
              cout << "Please choose a number between 1 - 12 bruh" << endl;
				}
        time_t curTime;
        curTime = time(NULL);
        if (dueDate != 0) {
            completionPerc = (difftime(curTime, dueDate) >= 0) ? 100 : (int) round((difftime(curTime, dateCreated) / difftime(dueDate, dateCreated)) * 100);
            cout << completionPerc << endl;
            cout << (difftime(curTime, dateCreated) / difftime(dueDate, dateCreated)) *   100 << endl;
            cout << ctime(&curTime) << endl;
        }
			}
      
		}
};

int Issue::count = 1;

int main() {
  
  time_t curTime;
  curTime = time(NULL);
  UserRole role = UserRole::ProjectLead;
  Issue i("Father", "Title");

  vector<string> collab{"Father", "Mother", "Kevin", "Dimitar", "Mihir"};
  
  i.mainMenu("Father", role, collab);
  /*
  Issue i2("I|1|Title|Father|_|1651285989|0|Task|VeryLow|Open|0.000000|_|_|");
  cout << i2 << endl; 

  time_t dateCreated = static_cast<time_t>(stoll("0", NULL, 0));
  time_t *t = &dateCreated;
  cout << ctime(t) << endl;  */
}
=======
				case(cmd) {
					case 1: 
						char s[120];
						cout >> "Please Input a New Title:" >> endl;
						cin.getline(s, 120);
						string str(s);

						setTitle(userName, role, s);
						break;
					case 2: 
						char s[120];
                                                cout >> "Please Input a New Due Date:" >> endl;
						// look up strftime and ask for that specifically with the stuff they have
                                                cin.getline(s, 120);
                                                string str(s);

						setDueDate(userName, role);
						break;
					case 3: 
						setPriority(
				}

				

				}			
			}
		}
		
};
>>>>>>> 7be2446c059673877a5c05c06952c729592ef67f
