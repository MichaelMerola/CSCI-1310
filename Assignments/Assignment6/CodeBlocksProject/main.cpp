#include <iostream>
#include "WeatherForecaster.h"

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    WeatherForecaster wForecaster;
    ForecastDay forecastData;

    fstream weatherData;
    weatherData.open("boulderData.txt"); //open the file

    if (weatherData.fail())
    {
        cout << "Something bad happened" << endl; // check if file opens successfully
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
                        forecastData.day = c;
                        j++;
                        break;
                    case 1:
                        forecastData.forecastDay = c;
                        j++;
                        break;
                    case 2:
                        forecastData.highTemp = stoi(c.substr(2));
                        j++;
                        break;
                    case 3:
                        forecastData.lowTemp = stoi(c.substr(2));
                        j++;
                        break;
                    case 4:
                        forecastData.humidity = stoi(c);
                        j++;
                        break;
                    case 5:
                        forecastData.avgWind = stoi(c);
                        j++;
                        break;
                    case 6:
                        forecastData.avgWindDir = c;
                        j++;
                        break;
                    case 7:
                        forecastData.maxWind = stoi(c);
                        j++;
                        break;
                    case 8:
                        forecastData.maxWindDir = c;
                        j++;
                        break;
                    case 9:
                        forecastData.precip = stod(c);
                        j++;
                        break;
                    default:
                        break;

                }//end switch

            }//end j while

            wForecaster.addDayToData(forecastData);
            i++;

        }//end i while

    }//end else

    string date;
    int temp;

    wForecaster.printDaysInData();
    cout << endl;

    cout << "Forecast statistics: " << endl;
    cout << "Last day it rained: " ; wForecaster.printLastDayItRained(); cout << endl;
    cout << "Total rainfall: " << wForecaster.calculateTotalPrecipitation() << endl;
    cout << "First date in data: " << wForecaster.getFirstDayInData() << endl;
    cout << "Last date in data: " << wForecaster.getLastDayInData() << endl;

    cout << endl;

    cout<< "Enter a date: " << endl;
    getline(cin, date);
    wForecaster.printForecastForDay(date);
    cout << endl;
    wForecaster.printFourDayForecast(date);
    cout << endl;

    wForecaster.printTemperatureForecastDifference(date);
    cout << endl;

    cout << "Predicted v Actual Rainfall: "; wForecaster.printPredictedVsActualRainfall(3); cout << endl;

    wForecaster.printLastDayAboveTemperature(85);
    cout << endl;


    return 0;
}
