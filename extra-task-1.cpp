#include <cfloat>
#include <cassert>
#include <cmath>
//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}


// Return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return  (minutes / 60.0) + (seconds / 3600.0) + hours;
}


//Return the hour as seen on a 24-hour clock. 
//hours is a number of hours since midnight.
double to_24_hour_clock(double hours)
{
        assert(hours >= 0);
        double i = trunc(hours);
        double d = fabs(hours - i);
        return (int)i % 24 + d;
}

//Returns the hours part of a time in seconds.
int get_hours(int seconds)
{
    return seconds / 3600;
}

//Returns the minutes part of a time in seconds.
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

//Returns the seconds part of a time in seconds.
int get_seconds(int seconds)
{
    return ((seconds % 3600) % 60) % 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from UTC+0.
double time_to_utc(int utc_offset, double time)
{
    if ((time - utc_offset) > 0)
    {
        return to_24_hour_clock(time - utc_offset);
    }
    else
        return to_24_hour_clock(24 + (time - utc_offset));
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    if ((time + utc_offset) > 0)
    {
        return to_24_hour_clock(time + utc_offset);
    }
    else
        return to_24_hour_clock(24 + (time + utc_offset));
}

int main()
{
    //seconds_difference Tests
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

    //hours_difference Tests
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

    //to_float_hours Tests
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    //to_24_hour_clock Tests
    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    //get_hours Tests
    assert(get_hours(3800) == 1);
    //get_minutes Tests
    assert(get_minutes(3800) == 3);
    //get_seconds Tests
    assert(get_seconds(3800) == 20);


    //time_to_utc Tests
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-6, 23.0) - 5.0) < DBL_EPSILON);

    //time_from_utc Tests
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);


}
