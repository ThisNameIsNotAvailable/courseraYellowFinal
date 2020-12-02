//
// Created by Alexey Valevich on 11/11/2020.
//
#pragma once

#include "date.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;


class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    string Last(const Date& d) const;

    template<class T>
    int RemoveIf(const T& pred) {
        int count = 0;
        auto it2 = helpBase.begin();
        auto  hNext = it2;
        for(auto it = base.begin(), next = it; it != base.end(); it = next, it2 = hNext) {
            next++;
            hNext++;
            auto bound = stable_partition(it->second.begin(), it->second.end(), [&](const string& ev){
                if (pred(it->first, ev)){
                    count++;
                    return false;
                }
                return true;
            });
            it->second.erase(bound, it->second.end());
            if(it->second.empty()) {
                base.erase(it);
                helpBase.erase(it2);
            }else
                it2->second = set<string>(it->second.begin(), it->second.end());
        }

        return count;
    }

    template<class T>
    vector<string> FindIf(const T& pred) const{
        vector<string> res;
        ostringstream os;
        for(const auto& entry : base) {
            for(const auto& event : entry.second) {
                os.str("");
                if(pred(entry.first, event)) {
                    os << entry.first << " " << event;
                    res.push_back(os.str());
                }
            }
        }
        return res;
    }

private:
    map<Date, vector<string>> base;
    map<Date, set<string>> helpBase;
};
