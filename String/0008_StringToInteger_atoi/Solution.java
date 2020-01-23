// Your runtime beats 18.83 % of java submissions.

class Solution
{
    private int findFirstNonWS(String str)
    {
        for (int idx = 0; idx < str.length(); ++idx)
        {
            char ch = str.charAt(idx);
            if (ch != ' ')
            {
                return idx;
            }
        }
        return str.length();
    }

    public int myAtoi(String str)
    {
        int output = 0;
        boolean isNegative = false;

        int firstNonWS = findFirstNonWS(str);
        if (firstNonWS == str.length())
        {
            return output;
        }

        if (str.charAt(firstNonWS) == '-')
        {
            isNegative = true;
            ++firstNonWS;
            if (firstNonWS >= str.length())
            {
                return output;
            }
        }
        else if (str.charAt(firstNonWS) == '+')
        {
            ++firstNonWS;
            if (firstNonWS >= str.length())
            {
                return output;
            }
        }

        for (int idx = firstNonWS; idx < str.length(); ++idx)
        {
            char ch = str.charAt(idx);
            int val = Character.digit(ch, 10);
            if (val < 0)
            {
                return isNegative ? -output : output;
            }

            if (output > Integer.MAX_VALUE / 10)
            {
                return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            output *= 10;

            if (!isNegative && output > Integer.MAX_VALUE - val)
            {
                return Integer.MAX_VALUE;
            }
            if (isNegative && output - 1 > Integer.MAX_VALUE - val)
            {
                return Integer.MIN_VALUE;
            }
            output += val;
        }
        return isNegative ? -output : output;
    }
}