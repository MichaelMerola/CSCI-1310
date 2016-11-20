#include <iostream>
using namespace std;

void calculateSimilarity(double *score, string DNA,	string unknown)
{
  double hamming = 0;

  for (int i = 0; i < DNA.length() ; i++)
  {
    if (DNA[i] != unknown[i])
      hamming++;
  }

*score = (DNA.length() - hamming)/(DNA.length());

} //end calc similarity

void calculateBestMatch(double *hamming, int *index,	string searchDNA,	string sub)
{
  int bestIndex;
  double bestHamming = -1;
  double currentHamming = 0;

  for (int i = 0; i < searchDNA.length(); i++)
  {
    for (int j = 0; j < sub.length(); j++)
    {
      if (sub[j] != searchDNA[i + j])
      {
        currentHamming++;
      }
    } //end j
    if (bestHamming == -1) // checks if bestHamming is empty on the first run
    {
      bestHamming = currentHamming;  // if bestHamming is empty than initialize it to the current hamming distance
      bestIndex = i;
    }
    else if (currentHamming < bestHamming) // checks if the current hamming distance is better than the best
      {
        bestHamming = currentHamming;
        bestIndex = i;
      }
    currentHamming = 0;
  } //end i

  *hamming = bestHamming;
  *index = bestIndex;


}// end calculate best match

int main()
{
  string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";

  string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";

  string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

  double localSim;
  double *score = &localSim;

  double simScoreHuman; //variable to store the similarity score between humanDNA and unknownDNA
  double simScoreMouse; //variable to store the similarity score between mouseDNA and unknownDNA

  calculateSimilarity(score, humanDNA, unknownDNA);
  simScoreHuman = localSim;

  calculateSimilarity(score, mouseDNA, unknownDNA);
  simScoreMouse = localSim;

  if (simScoreHuman > simScoreMouse)
    cout << "Human" << endl;

  else if (simScoreHuman < simScoreMouse)
    cout << "Mouse" << endl;

  else
    cout << "Identity cannot be determined." << endl;

  cout << endl;

  string subStr;
  double hamming;
  double *hamPtr = &hamming;
  int index;
  int *dexPtr = &index;

  string bestMatch;
  double bestMatchScore;

  cout << "Enter a substring: " ;
  getline(cin, subStr);

  cout << endl;

  calculateBestMatch(hamPtr, dexPtr, mouseDNA, subStr);

  for (int i = 0; i < subStr.length(); i++)
  {
    bestMatch += mouseDNA[index + i]; // builds the best match substring based on the index recieved from calculateBestMatch
  }

  bestMatchScore = (subStr.length() - hamming); // calculates the bestMatchScore using the best hamming distance from calculateBestMatch

  cout << "Best Match: " << bestMatch << endl;
  cout << "Best Match Score: " << bestMatchScore << endl;

  return 0;
} //end main
