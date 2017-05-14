#include <vector>
#include "palya.hpp"

using namespace std;

int main()
{
    vector<vector<Widget*>> w;
    int XX = 800;
    int YY = 600;
    int m = 25;
    Palya p(w, XX, YY, m);
    p.event_loop();

    return 0;
}
