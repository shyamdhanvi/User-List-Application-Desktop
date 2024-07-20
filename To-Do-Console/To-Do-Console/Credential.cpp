//#include "HeaderFiles\Credential.h"
#include "HeaderFiles\Credential.h"
#include "HeaderFiles\UserData.h"
//#include "HeaderFiles\UserName.h"
using namespace std;
void credential::set_Credentials() {
	UserData userdata;
	set_Credentails.emplace(userdata.get_UserName(), userdata.get_Password());
}
const list<pair<string, string>>& credential::get_Cerdentials() const
{
	return User_Credentials;
}