#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Error\n");
    return 1;
  }

  int search_val;
  int my_arr[argc - 1];
  for (int i = 0; i < argc - 1; i++) {
    my_arr[i] = atoi(argv[i + 1]);
  }
  int sum_ordered = 0;
  while (sum_ordered != (argc - 2)) {
    sum_ordered = 0;
    for (int i = 0; i < argc - 2; i++) { //can decrement end value (BUBBLE SORT)
      if (my_arr[i] > my_arr[i + 1]) {
        int temp = my_arr[i];
        my_arr[i] = my_arr[i + 1];
        my_arr[i + 1] = temp;
      } else {
        sum_ordered++;
      }
    }
  }
  printf("Search value: ");
  scanf("%i", &search_val);
  for (int i = 0; i < argc - 1; i++) {
    printf("%i ", my_arr[i]);
  }
  printf("\n");
  int current_index = (argc - 1) / 2;
  int previous_index = current_index;
  int step = current_index / 2;
  int found = 0;
  while (current_index <= (argc - 2) && current_index >= 0 && !found) {
    printf("Index: %i, Step: %i\n", current_index, step);
    if ((search_val < my_arr[current_index]) &&
        (current_index - step != previous_index)) {
      current_index -= step;
    } else if ((search_val > my_arr[current_index]) &&
               (current_index + step != previous_index)) {
      current_index += step;
    } else if (search_val == my_arr[current_index]) {
      printf("Index is %i\n", current_index);
      found = 1;
    } else {
      break;
    }
    if (!found && step > 1) {
      step /= 2;
    }
  }
  if (!found) {
    printf("Not found.\n");
  }
  return 0;
}
