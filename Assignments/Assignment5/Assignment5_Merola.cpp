// Michael Merola
// Camilla
// CSCI 1310 Assignment 5

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Forecast{
 string day;
 string castedDay;
 int highTemp;
 int lowTemp;
 int humidity;
 int avgWind;
 string avgWindDir;
 int maxWind;
 string maxWindDir;
 double precip;
};

string lastDayItRained(Forecast forecastData[])
{
    for (int i = 984; i >= 0; i--)
    {
        if (forecastData[i].day == forecastData[i].castedDay)
        {
            if (forecastData[i].precip > 0)
            {
                return forecastData[i].day;
            }

        }
    }
    cout << "It has not rained during the time frame of this data." << endl;
    return NULL;
}

double totalRainfall(Forecast forecastData[])
{
    double totRain = 0;

    for (int i = 0; i <= 984; i++)
    {
        if (forecastData[i].day == forecastData[i].castedDay)
            {
                totRain += forecastData[i].precip;
            }
    }
    return totRain;
}

int maxWindspeed(Forecast forecastData[])
{
    int maxIndex = 0;
    int maxWind = 0;

    for (int i = 0; i <= 984; i++)
    {
        if (forecastData[i].day == forecastData[i].castedDay)
        {
            if (forecastData[i].maxWind > maxWind)
            {
                maxIndex = i;
                maxWind = forecastData[i].maxWind;
            }

        }
    }
    return maxIndex;
}

int maxRainfall(Forecast forecastData[])
{
    int maxIndex;
    double maxRain;

    for (int i = 0; i <= 984; i++)
    {
        if (forecastData[i].day == forecastData[i].castedDay)
        {

            if (forecastData[i].precip > maxRain)
            {
                maxIndex = i;
                maxRain = forecastData[i].precip;
            }

        }
    }
    return maxIndex;
}

int maxTempDifference(Forecast forecastData[])
{
    int maxIndex;
    int maxDiff;

    for (int i = 0; i <= 984; i++)
    {
        if (forecastData[i].day == forecastData[i].castedDay)
        {
            if ((forecastData[i].highTemp - forecastData[i].lowTemp) > maxDiff)
            {
                maxIndex = i;
                maxDiff = forecastData[i].highTemp - forecastData[i].lowTemp;
            }

        }
    }
    return maxIndex;
}

Forecast forecastForDay(Forecast forecastData[], string day)
{
    for (int i = 0; i <= 984; i++)
    {
        if (forecastData[i].day == forecastData[i].castedDay && forecastData[i].day == day)
            {
                return forecastData[i];
            }
    }
}

int main()
{
    Forecast forecastData[1000]; //create array of structs

    fstream weatherData;
    weatherData.open("boulderData.txt"); //open the file

    if (weatherData.fail())
    {
        cout << "Something bad happened" << endl; // check if file opens sucessfully
    }
    else
    {
        string line;
        int i = 0;
        int j = 0;
        while (getline(weatherData, line))//run through all lines of data
        {
            stringstream ss(line);
            string c;
            j = 0;

            while (getline(ss, c, ',')) //check through each c value
            {
                switch (j)
                {
                    case 0:
                        forecastData[i].day = c;
                        j++;
                        break;
                    case 1:
                        forecastData[i].castedDay = c;
                        j++;
                        break;
                    case 2:
                        forecastData[i].highTemp = stoi(c.substr(2));
                        j++;
                        break;
                    case 3:
                        forecastData[i].lowTemp = stoi(c.substr(2));
                        j++;
                        break;
                    case 4:
                        forecastData[i].humidity = stoi(c);
                        j++;
                        break;
                    case 5:
                        forecastData[i].avgWind = stoi(c);
                        j++;
                        break;
                    case 6:
                        forecastData[i].avgWindDir = c;
                        j++;
                        break;
                    case 7:
                        forecastData[i].maxWind = stoi(c);
                        j++;
                        break;
                    case 8:
                        forecastData[i].maxWindDir = c;
                        j++;
                        break;
                    case 9:
                        forecastData[i].precip = stod(c);
                        j++;
                        break;
                    default:
                        break;

                }//end switch

            }//end while
            i++;
        }
    }
    string date;

    cout << "Forecast statistics: " << endl;
    cout << "Last day it rained: " << lastDayItRained(forecastData) << endl;
    cout << "Total rainfall: " << totalRainfall(forecastData) << endl;
    cout << "Maximum wind speed: " << forecastData[maxWindspeed(forecastData)].maxWind << " mph on " << forecastData[maxWindspeed(forecastData)].day << endl;
    cout << "Maximum rainfall: " << forecastData[maxRainfall(forecastData)].precip << " inches on " << forecastData[maxRainfall(forecastData)].day << endl;
    cout << "Maximum temperature difference: " << (forecastData[maxTempDifference(forecastData)].highTemp - forecastData[maxTempDifference(forecastData)].lowTemp) << " F on " << forecastData[maxTempDifference(forecastData)].day << endl;

    cout<<"Enter a date: ";
    getline(cin, date);
    Forecast dayForecast = forecastForDay(forecastData, date);

    cout << "Forecast for " << dayForecast.day << endl;
    cout << "H: " << dayForecast.highTemp << endl;
    cout << "L: " << dayForecast.lowTemp << endl;
    cout << "Humidity: " << dayForecast.humidity << endl;
    cout << "Avg. wind: " << dayForecast.avgWind << endl;
    cout << "Avg. wind direction: " << dayForecast.avgWindDir << endl;
    cout << "Max wind: " << dayForecast.maxWind << endl;
    cout << "Max wind direction: " << dayForecast.maxWindDir << endl;
    cout << "Precipitation: " << dayForecast.precip << endl;

    return 0;

} //end main


