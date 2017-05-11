#include <vector>
#include "palya.hpp"

using namespace std;

int main()
{
    vector<vector<Widget*>> w;
    int XX = 600;
    int YY = 600;
    int m = 30;
    Palya p(w, XX, YY, m);
    p.event_loop();

    return 0;
}
