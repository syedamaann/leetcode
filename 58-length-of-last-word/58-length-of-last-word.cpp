class Solution
{
public:
  int lengthOfLastWord(std::string s)
  {
    int length = 0;

    while (s.back() == ' ')
    {
      s.pop_back();
    }

    for (auto it = s.crbegin(); it != s.crend(); ++it)
    {
      if (*it != ' ')
      {
        length++;
      }
      else
      {
        break;
      }
    }

    return length;
  }
};