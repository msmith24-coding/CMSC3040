#include <string>
#include <vector>

const int n = 15;

int main()
{
    // Question 1:
    std::vector<int> countVec(26);
    
    // Question 2:
    std::vector<std::string> wordVec;
    
    // Question 3:
    std::vector<int> sequencerVec(n);
    for(unsigned int i = 0; i < sequencerVec.size(); ++i) {
        sequencerVec[i] = i;
    }

    // Question 4:
    auto position = wordVec.begin() + 9;
    wordVec.insert(position, "zero");

    // Question 5:
    wordVec.push_back("zero");

    // Question 6:
    wordVec.insert(wordVec.begin(), "zero");

    // Question 7:
    std::string element10 = wordVec.at(10);

    // Question 8:
    std::string element0 = wordVec.front();

    return 0;
}
