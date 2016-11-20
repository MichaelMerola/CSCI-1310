#include "WeatherForecaster.h"

#include <iostream>

using namespace std;

WeatherForecaster::WeatherForecaster()
{
    arrayLength = 984;
    index = 0;
}

WeatherForecaster::~WeatherForecaster()
{}

void WeatherForecaster::addDayToData(ForecastDay d)
{
    yearData[index] = d; // add day d to the array
    index++;
}

void WeatherForecaster::printDaysInData()
{
    //Show the dates in the data set where the day and the forecast day are the same.

    for (int i = 0; i < arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay)// checks if both days are the same
        {
            cout << yearData[i].day << endl;
        }
    }
}//end printDaysInData

void WeatherForecaster::printForecastForDay(string date)
{
    //Take a date as an argument and shows the forecast for that date.

    for (int i = 0; i <= arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay && yearData[i].day == date)
        {
            cout << yearData[i].day << endl;
            cout << "Forecast for " << yearData[i].forecastDay << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max Wind: " << yearData[i].maxWind << endl;
            cout << "Max Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl;
            cout << endl;

        }//end if
    }//end for
}//end printForecastForDay

void WeatherForecaster::printFourDayForecast(string date)
{
    /*Takes a date as an argument and shows the forecast issued on that
    date and for the next three days. For example, for a date of 1-
    26-2016, you would show the forecast for 1-26-2016 issued on 1-
    26-2016 as well as the forecast for 1-27, 1-28, and 1-29 issued
    on 1-26.*/

    for (int i = 0; i <= arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay && yearData[i].day == date)
        {
            while (yearData[i].day == date)//move through all instances that include the given date
            {
                cout << yearData[i].day << endl;
                cout << "Forecast for " << yearData[i].forecastDay << endl;
                cout << "H: " << yearData[i].highTemp << endl;
                cout << "L: " << yearData[i].lowTemp << endl;
                cout << "Humidity: " << yearData[i].humidity << endl;
                cout << "Avg. Wind: " << yearData[i].avgWind << endl;
                cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
                cout << "Max Wind: " << yearData[i].maxWind << endl;
                cout << "Max Wind Direction: " << yearData[i].maxWindDir << endl;
                cout << "Precipitation: " << yearData[i].precip << endl;
                cout << endl;

                i++;
            }//end while

        }//end if
    }//end for
}//end printFourDayForecast

double WeatherForecaster::calculateTotalPrecipitation()
{
    //Returns the sum of the precipitation in the data set.

    double precipSum = 0;

    for (int i = 0; i <= arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay)
        {
           precipSum += yearData[i].precip; //adds all precip to variable
        }
    }//end for

    return precipSum;

}//end calculateTotalPrecipitation

void WeatherForecaster::printLastDayItRained()
{
    //Shows the date of the last measurable precipitation.

    for (int i = arrayLength; i >= 0; i--)
    {
        if (yearData[i].day == yearData[i].forecastDay)
        {
            if (yearData[i].precip > 0)
            {
                cout << yearData[i].day << endl;
                cout << endl;
                break;
            }

        }//end if
    }//end for

}//end WeatherForecaster

void WeatherForecaster::printLastDayAboveTemperature(int temp)
{
    /*Takes an integer as an argument and shows the date for the last
    day above that temperature. If no days are above the temperature,
    prints “No days above that temperature.”*/
    bool foundDay = false;

    for (int i = arrayLength; i >= 0; i--)
    {
        if (yearData[i].day == yearData[i].forecastDay)
        {
            if (yearData[i].highTemp > temp)
            {
                cout << yearData[i].day << endl;
                foundDay = true;
                break;
            }

        }//end if
    }//end for
    if (foundDay == false)
    {
        cout << "No days above that temperature." << endl;
    }

}//end printLastDayAboveTemperature

void WeatherForecaster::printTemperatureForecastDifference(string date)
{
    /*Takes a date as an argument and shows the temperature forecast
    for that date for the three days leading up to the date and the
    day-of forecast.*/

    for (int i = 0; i <= arrayLength; i++)
    {
        if (date == yearData[i].forecastDay)
        {
            cout << "Forecast for " << yearData[i].day ;
            cout << " issued on " << yearData[i].forecastDay << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;

            cout << endl;

        }//end if
    }//end for

}//end printTemperatureForecastDifference

void WeatherForecaster::printPredictedVsActualRainfall(int daysOut)
{
    //Shows the difference between the predicted and actual rainfall total in the entire data set.
    //The argument to the function is the number of forecast days away.
    double diffSum = 0;
    int backParse = 0;

    for (int i = 0; i < arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay)
        {
            for (int j = i; j >= 0; j--)
            {
                if (backParse == (daysOut*3))
                {
                    if (yearData[j].forecastDay == yearData[i].forecastDay)
                    {
                        diffSum += (yearData[i].precip - yearData[j].precip);
                    }
                    backParse = 0;
                    break;
                }
            backParse++;
            }
        }//end if
    }//end for

    cout << diffSum << endl;

}//end printPredictedVsActualRainfall

string WeatherForecaster::getFirstDayInData()
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (yearData[i].day == yearData[i].forecastDay)// checks if both days are the same
        {
            return yearData[i].day;
        }
    }//end for
}//end getFirstDayInData

string WeatherForecaster::getLastDayInData()
{
    for (int i = arrayLength; i >= 0; i--)
    {
        if (yearData[i].day == yearData[i].forecastDay)// checks if both days are the same
        {
            return yearData[i].day;
        }
    }//end for
}//end getLastDayInData
