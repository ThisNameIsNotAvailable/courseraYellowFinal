

#include "database.h"
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>




string Database::Last(const Date& d) const{
    auto it = base.upper_bound(d);

    if(it == base.begin()) {
        throw invalid_argument("invalid");
    } else {
        ostringstream os;
        os << prev(it)->first << " " << base.at(prev(it)->first).back();
        return os.str();
    }

}
void Database::Add(const Date& date, const string& event) {
    auto success = helpBase.insert(make_pair(date, set<string>{event}));
    if(success.second) {
        base.insert(make_pair(date, vector<string>{event}));
    }else{
        auto success2 = helpBase[date].insert(event);
        if(success2.second) {
            base[date].push_back(event);
        }
    }
}

void Database::Print(ostream& os) const{
    for(const auto& entry : base) {
        for (const string& event : entry.second) {
            os << entry.first << " " << event << endl;
        }
    }
}

