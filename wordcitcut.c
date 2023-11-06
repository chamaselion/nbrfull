#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void	to_words_main(int nbr, char *result, int segment);
void kinda_printf(char *result);

void segmentscitcat(char **segments, int numSegments, char *result)
{
    int l; // We'll use this to loop through the segments
    
    l = 0; // Starting at the first segment
    while (l < numSegments) // For each segment...
    {
        if (segments[l] != NULL) // If the segment isn't empty...
        {
            strcat(result, segments[l]); // Add it to the result
            free(segments[l]); // And free up the memory we used for it
        }
        l++; // Move on to the next segment
    }
}

void segmentsin(char **segments, int numSegments)
{
    int j; // We'll use this to loop through the segments
    
    j = 0; // Starting at the first segment
    while (j < numSegments) // For each segment...
    {
        segments[j] = NULL; // Set it to NULL
        j++; // Move on to the next segment
    }
}

// This function prints the result


// This function processes a segment of the number
void process_segment(char *nbr, int start, int end, int segment, char **segments, int *has_value, int num_segments)
{
    char segment_str[4]; // This will hold the segment as a string
    char *segment_words; // This will hold the words for the segment
    int current_segment; // This will hold the segment as an integer

    // Copy the segment from the number to segment_str
    strncpy(segment_str, &nbr[start], end - start + 1);
    segment_str[end - start + 1] = '\0'; // Add a null terminator
    current_segment = atoi(segment_str); // Convert segment_str to an integer
    if (current_segment > 0) // If the segment isn't zero...
    {
        // Allocate memory for the words
        segment_words = malloc(128 * sizeof(char));
        segment_words[0] = '\0'; // Start with an empty string
        // Convert the segment to words
        to_words_main(current_segment, segment_words, segment);
        if (*has_value) // If we've already added words...
            strcat(segment_words, ", "); // Add a comma
        // Add the words to the segments
        segments[num_segments - segment - 1] = segment_words;
        *has_value = 1; // We've added words
    }
}

// This function cuts the number into segments and converts each one to words
void wordcitcut(char *nbr, int length, int num_segments)
{
    char result[1024] = ""; // This will hold the final result
    int has_value; // This will be 1 if we've added any words
    int segment; // This will hold the current segment number
    int start; // This will hold the start index of the current segment
    int end; // This will hold the end index of the current segment
    char *segments[num_segments]; // This will hold the words for each segment
    int k; // This will hold the index of the last digit in the current segment

    // Initialize all the segments to NULL
    segmentsin(segments, num_segments);
    has_value = 0; // We haven't added any words yet
    segment = 0; // Start with the first segment
    k = length - 1; // The last digit is at the end of the number
    while (k >= 0) // While there are still digits left...
    {
        if (k - 2 < 0) // If there are less than 3 digits left...
            start = 0; // Start at the first digit
        else // Otherwise...
            start = k - 2; // Start 2 digits back
        end = k; // The end is at the current digit
        // Process the current segment
        process_segment(nbr, start, end, segment, segments, &has_value, num_segments);
        k -= 3; // Move back 3 digits
        segment++; // Move on to the next segment
    }
    // Concatenate all the segments
    segmentscitcat(segments, num_segments, result);
    // Print the result
    kinda_printf(result);
}
