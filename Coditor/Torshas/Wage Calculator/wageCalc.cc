#include <bits/stdc++.h>
using namespace std;

#define DAYS 7
#define STANDARD_WORKING_HOURS 40
#define STANDARD_PER_HOUR_WAGE_RATE 200.00
#define STANDARD_WORKING_HOUR_PER_DAY 8
#define NORMAL_DAILY_OVERTIME_RATE 250.00
#define NORMAL_WEEKLY_OVERTIME_RATE 300.00
#define SUNDAY_BONUS_RATE 0.50
#define SATURDAY_BONUS_RATE 1.25

void solve() {
    int workHrs[DAYS], totalHRS = 0;
    float totWage = 0.00, dailyWage = 0.00, extraBonus = 0.00, sunBonus = 0.00, satBonus = 0.00, weekBonus = 0.00;

    for(int i = 0; i < DAYS; i++) {
        cin >> workHrs[i];
        if(i > 0 && i < DAYS-1) {
            totalHRS += workHrs[i];
        }
    }
    if(totalHRS > STANDARD_WORKING_HOURS) {
        weekBonus = (totalHRS - STANDARD_WORKING_HOURS) * (NORMAL_WEEKLY_OVERTIME_RATE);
    }
    for(int i = 0; i < DAYS; i++) {
        if(workHrs[i] <= STANDARD_WORKING_HOUR_PER_DAY) {
            dailyWage = workHrs[i] * STANDARD_PER_HOUR_WAGE_RATE;
        }
        else {
            dailyWage = STANDARD_WORKING_HOUR_PER_DAY * STANDARD_PER_HOUR_WAGE_RATE;
            extraBonus = (workHrs[i] - STANDARD_WORKING_HOUR_PER_DAY) * NORMAL_DAILY_OVERTIME_RATE;
        }
        totWage += dailyWage + extraBonus;
        if(i == 0) {
            sunBonus = (extraBonus + dailyWage) * SUNDAY_BONUS_RATE;
            totWage += sunBonus;
        }
        if(i == DAYS - 1) {
            satBonus = (extraBonus + dailyWage) * SATURDAY_BONUS_RATE;
            totWage += satBonus;
        }
    }
    printf("INR %.2f", (totWage + extraBonus));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}