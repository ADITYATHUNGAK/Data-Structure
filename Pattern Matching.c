/*Program in C for the following operations on Strings.
a) Read a mainString(STR),a PatternString(PAT)and aReplace String(REP)
b) Perform Pattern Matching Operation: Find and Replace all occurrences of PAT inSTR with REP if PAT
exists in STR. Report suitable messages in case PAT does notexist in STR.*/

#include<stdio.h>

void main() {
    char STR[100], PAT[100], REP[100], ans[100];  // Arrays for main string, pattern, replacement, and result
    int i, j, c, m, k, flag = 0;  // Variables for indexing and flag for pattern found

    // Input the main string
    printf("\nEnter the MAIN string: \n");
    scanf(" %[^\n]", STR);  // Read the main string including spaces

    // Input the pattern string
    printf("\nEnter the PATTERN string: \n");
    scanf(" %[^\n]", PAT);  // Read the pattern string

    // Input the replacement string
    printf("\nEnter the REPLACEMENT string: \n");
    scanf(" %[^\n]", REP);  // Read the replacement string

    i = m = c = j = 0;  // Initialize indices for pattern, main string, and result

    // Traverse through the main string
    while (STR[c] != '\0') {
        // Checking for pattern match at the current position
        if (STR[m] == PAT[i]) {  // If characters match
            i++;  // Move to the next character of the pattern
            m++;  // Move to the next character of the main string

            // If we've reached the end of the pattern, it means we have found a match
            if (PAT[i] == '\0') {
                flag = 1;  // Set flag to indicate that the pattern is found

                // Copy the replacement string (REP) to the result string (ans)
                for (k = 0; REP[k] != '\0'; k++, j++) {
                    ans[j] = REP[k];  // Append the replacement string characters to ans
                }

                // Reset pattern index (i) and move the main string index (c) to the end of the matched part
                i = 0;
                c = m;  // Move the main string index to continue after the replaced pattern
            }
        } else {
            // If characters do not match, copy the current character from STR to ans
            ans[j] = STR[c];
            j++;
            c++;  // Move to the next character in the main string
            m = c;  // Reset the match index to the current main string position
            i = 0;  // Reset the pattern index
        }
    }

    // Check if the pattern was found and print the appropriate result
    if (flag == 0) {
        printf("\nPattern NOT found in the MAIN string.\n");
    } else {
        ans[j] = '\0';  // Null-terminate the result string
        printf("\nThe RESULTANT string is: %s\n", ans);  // Print the modified string
    }
}
