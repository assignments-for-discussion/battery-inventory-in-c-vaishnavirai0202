#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  int ratedCapacity=120;
  for(int i=0;i<nBatteries;i++){
    float SOH= ((float)presentCapacities[i]/ratedcapacity)*100;
    if(SOH>80){
      counts.healthy++;
    }
    else if(SOH>=62){
      counts.exchange++;
    }
    else{
      counts.failed++;
    }
  }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities1[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries1 = sizeof(presentCapacities1) / sizeof(presentCapacities1[0]);
  printf("Test case 1 : Counting batteries by SoH...\n");
  struct CountsBySoH counts1 = countBatteriesByHealth(presentCapacities1, numberOfBatteries1);
  assert(counts1.healthy == 2);
  assert(counts1.exchange == 3);
  assert(counts1.failed == 1);
  printf("Done counting test case1:)\n");

  const int presentCapacities2[] = {119, 30, 45, 85, 92, 97};
  const int numberOfBatteries2 = sizeof(presentCapacities2) / sizeof(presentCapacities2[0]);
  printf("Test case 2 Counting batteries by SoH...\n");
  struct CountsBySoH counts2 = countBatteriesByHealth(presentCapacities2, numberOfBatteries2);
  assert(counts2.healthy == 2);
  assert(counts2.exchange == 2);
  assert(counts2.failed == 2);
  printf("Done counting test case 2:)\n");

  const int presentCapacities3[] = {111, 20, 35, 40, 22, 100};
  const int numberOfBatteries3 = sizeof(presentCapacities3) / sizeof(presentCapacities3[0]);
  printf("Test case 3 Counting batteries by SoH...\n");
  struct CountsBySoH counts3 = countBatteriesByHealth(presentCapacities3, numberOfBatteries3);
  assert(counts3.healthy == 2);
  assert(counts3.exchange == 0);
  assert(counts3.failed == 4);
  printf("Done counting test case 3:)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
