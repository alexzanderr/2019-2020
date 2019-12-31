#include <iostream>
#include "util.h"
#include <string>
#include "range.h"
#include <any>
#include <vector>
#include "exceptions.h"
#include "list.h"

using namespace std;
using namespace Util::PythonBuiltIn;
using namespace Util::Memory;

int main() {

    try {
        
        List list;
        list.append("TExt.");
        list.append(123);
        list.append(12.123f);
        list.append('c');
        list.append("else");
        for(size_t iter = 0; iter < 5; iter++) {
            int x = iter + 10;
            list.append(x);
        }
        print(list);
        print(list["::-1"]);
        print(list["1:4"]);
        print(list["::2"]);
        print(list["1:8:2"]);
        print(type(list));
        print(type(123));
        
    }
    catch (TypeError err){
        cout << err.GetMessage();
    }
    catch(ParameterError err) {
        //cout << err.message;
        cout << err.GetMessage();
    }
    catch(...) {
        cout << "We have an error here but we dont know about it.";
    }
    return 0;
}