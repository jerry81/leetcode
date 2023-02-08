/*

45. Jump Game II
Medium
10.8K
376
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000


*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

unordered_map<int, int> lookup;

bool lu(int k) {
  return lookup.find(k) != lookup.end();
}
int jumpR(vector<int> nums, int idx) {
  if (lu(idx)) return lookup[idx];

  vector<int> choices;

  int jumpMax = nums[idx];

  if (jumpMax == 0) {
    lookup[idx] = 100000000;
    return 100000000;
  }

  if ((jumpMax + idx) >= (nums.size() - 1)) {
    lookup[idx] = 1;
    return 1;
  }

  for (int i = 1; (i <= jumpMax); ++i) {
    int k = idx+i;
    int choice = 1;
    int added = 0;
    if (lu(k)) {
      added = lookup[k];
    } else {
      lookup[k] = jumpR(nums, k);
      added = lookup[k];
    }
    choice += added;

    choices.push_back(choice);
  }

  int res = *min_element(choices.begin(), choices.end());
  lookup[idx] = res;
  return res;
}

int jumpGreedy(vector<int>& nums) {
  int i = 0;
  int steps = 0;
  while (i < (nums.size() - 1)) {
    int cur = nums[i];

    int max = 0;
    int maxI = 0;
    if ((i + cur) >= (nums.size() - 1)) return (steps + 1);
    for (int idx = 1; idx <= cur; ++idx) {

      int candidate = i + idx;
      int comparator = nums[candidate] + (candidate - cur);
      if (comparator > max) {
        max = comparator;
        maxI = candidate;
      }
    }
    steps++;
    i = maxI;
  }
  return steps - 1;
}

public:
    int jump(vector<int>& nums) {
      // lookup.clear();
      // lookup[nums.size()-1] = 0;
      // return jumpR(nums,0);
      if (nums.size() == 1) return 0;
      return jumpGreedy(nums);
    }
};

int main() {
  Solution s;
  vector<int> test1 = {2,3,1,1,4};
  cerr << "expect 2 " << s.jump(test1) << endl;
  vector<int> test2 = {2,3,0,1,4};
  cerr << "expect 2 " << s.jump(test2) << endl;
  vector<int> loadtest = {8,4,3,4,0,0,9,7,2,3,5,7,3,1,1,5,1,8,6,1,1,6,1,1,8,0,4};
  cerr << "expect something " << s.jump(loadtest) << endl;
  vector<int> loadtest2 = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
  cerr << "expect something " << s.jump(loadtest2) << endl;
  vector<int> loadtestBig = {130,516,536,655,561,404,132,660,917,857,39,143,585,341,962,390,914,593,223,603,536,469,657,984,952,598,397,298,291,647,239,215,557,932,17,98,174,734,442,325,781,181,224,35,129,587,898,396,570,173,673,593,977,666,210,597,830,293,358,67,300,10,189,893,544,724,219,182,710,164,274,778,247,172,236,171,470,988,149,239,324,480,343,996,397,582,560,962,213,327,997,703,11,326,919,207,693,549,231,935,724,600,78,700,2,348,952,16,998,58,833,638,845,459,305,605,588,296,279,95,515,859,235,58,441,117,574,160,225,302,715,913,178,649,772,903,645,567,977,119,874,639,986,208,177,795,390,649,329,605,733,26,718,754,521,651,271,935,287,203,837,768,869,868,415,103,779,362,73,265,118,800,570,556,341,183,308,496,309,757,582,38,788,156,576,918,47,358,495,528,145,76,259,985,925,16,411,320,297,718,463,594,806,157,156,269,951,584,898,375,536,351,579,878,823,837,661,42,948,86,541,940,293,750,70,393,49,110,270,176,221,279,922,961,241,387,900,736,330,291,131,962,907,73,395,834,799,361,375,639,194,3,728,253,240,593,746,388,993,727,816,741,976,22,30,818,871,316,852,163,336,604,314,915,36,299,284,337,591,439,139,1,654,363,180,388,392,346,285,172,630,931,347,25,862,837,831,21,666,600,323,440,104,866,361,880,458,86,53,645,170,149,836,916,481,337,27,736,495,624,934,289,724,332,274,90,173,158,7,280,507,498,145,707,296,176,679,964,746,397,730,779,739,335,44,310,954,378,583,635,976,943,466,63,919,893,36,866,875,531,519,100,137,291,347,847,571,794,165,665,282,949,562,29,147,894,569,277,579,477,733,379,979,715,949,50,758,894,406,186,249,310,619,799,425,977,656,236,400,770,167,559,649,807,504,250,499,606,719,553,367,546,971,926,428,558,687,426,570,336,239,473,654,459,891,117,383,172,842,612,138,62,501,794,386,803,956,955,949,119,311,464,71,409,362,987,742,919,943,19,846,73,683,240,842,29,100,42,523,518,206,133,136,725,825,893,748,952,596,256,319,751,250,599,292,858,666,969,213,605,647,33,894,105,522,977,504,143,853,137,843,987,779,57,269,905,696,379,273,191,519,979,748,533,809,459,314,183,682,531,186,413,279,562,974,483,265,718,368,119,448,222,507,926,703,726,553,875,794,587,996,562,813,961,619,753,623,820,742,147,506,784,508,147,892,819,60,868,887,70,442,713,126,982,421,444,437,611,959,644,674,455,139,54,333,715,22,972,61,133,389,400,428,387,298,116,91,732,772,267,473,395,547,103,592,98,623,122,987,375,233,423,163,784,172,176,556,190,259,656,420,752,812,207,808,594,882,290,527,549,519,663,590,662,753,485,331,31,668,909,520,645,256,872,372,83,772,233,835,797,330,310,271,714,819,300,444,156,745,773,861,966,983,566,551,658,940,6,465,47,930,234,299,676,995,450,460,537,356,215,189,89,720,490,483,535,343,957,969,805,60,913,813,997,654,706,755,996,788,587,508,240,877,510,823,159,35,904,896,586,594,537,406,315,264,250,937,139,280,81,994,641,745,971,606,138,755,132,590,682,112,207,953,131,742,450,916,965,658,717,43,485,842,864,996,389,843,565,306,998,351,958,675,428,298,156,99,654,839,739,783,460,124,290,249,312,862,519,349,915,576,483,944,672,701,535,491,591,950,406,777,980,241,969,203,607,610,96,162,180,577,166,58,956,538,497,59,698,612,656,283,361,897,85,148,884,189,722,543,79,975,55,833,306,739,855,627,435,34,414,866,188,716,716,718,908,59,622,390,779,914,847,779,635,323,740,716,247,607,651,515,97,297,533,950,134,895,671,125,634,496,975,906,639,523,60,693,782,746,311,710,556,764,894,877,702,55,410,246,352,136,877,584,900,660,806,690,894,146,697,156,659,446,327,755,4,671,999,335,781,703,461,848,716,699,744,379,919,151,51,659,208,119,811,319,684,52,780,816,956,740,365,25,501,966,749,846,584,723,756,763,845,801,428,172,121,238,929,412,601,328,983,146,692,208,500,191,310,292,408,135,177,504,130,249,738,899,424,49,37,981,889,88,575,564,742,609,379,764,964,526,481,880,60,114,176,334,334,389,635,878,537,320,520,464,33,259,95,747,723,623,347,379,13,777,188,21,348,543,419,73,582,963,867,344,96,572,576,992,815,388,675,151,724,968,182,982,849,329,689,930,349,350,458,420,861,722,960,972,802,527,552,942,18,225,331,633,60,77,789,243,640,576,458,745,982,72,14,1,799,252,843,436,937,561,984,686,482,29,336,729,706,641,601,532,827,253,518,124,612,751,547,451,666,160,24,109,743,35,274,782,363,138,899,746,474,819,881,805,873,104,618,888,388,318,555,597,33,870,568,909,151,971,166,279,578,59,208,864,899,622,464,377,546,369,680,377,420,943,396,194,916,297,120,29,362,991,736,409,808,487,117,414,698,483,2,795,104,980,14,345,438,600,423,506,248,107,19,465,405,742,422,224,764,543,913,750,755,643,882,303,63,11,429,292,605,884,113,163,712,918,259,838,280,723,767,943,221,162,833,484,733,169,46,761,514,45,275,132,82,129,619,977,83,630,60,108,672,424,723,852,988,92,322,199,352,265,614,711,661,92,34,169,186,574,221,622,702,170,44,13,355,539,889,586,651,486,394,421,556,753,509,939,60,822,567,739,506,80,289,394,923,104,571,985,41,89,380,968,271,365,357,602,696,174,125,325,808,963,584,851,323,717,497,567,959,938,45,907,640,948,475,144,475,558,908,625,180,72,92,178,629,831,426,20,40,44,252,125,43,864,550,481,464,782,271,26,321,866,900,903,159,456,508,70,239,159,32,3,316,7,102,757,934,392,411,354,400,832,143,2,259,109,27,623,303,460,363,572,932,843,400,792,610,542,109,947,346,90,896,102,629,635,745,880,71,318,878,674,859,250,849,750,804,761,966,708,879,593,863,947,711,137,348,50,168,829,563,16,162,687,728,492,441,497,358,227,918,322,100,175,805,441,886,119,609,617,473,847,656,721,239,172,985,989,555,243,993,888,861,432,108,522,461,933,256,155,64,355,184,993,26,774,393,798,26,689,57,364,111,563,1000,782,517,875,945,837,421,923,328,510,418,702,282,668,271,834,465,220,475,851,571,11,635,792,870,16,758,516,643,550,544,957,212,814,193,576,12,253,503,269,834,293,852,432,156,974,917,132,539,352,943,507,105,828,240,729,49,519,284,529,630,560,723,89,906,626,279,925,84,343,32,448,283,915,250,607,669,782,644,599,235,154,78,115,756,98,22,943,954,894,880,588,834,517,799,336,927,815,855,454,597,279,331,314,999,81,997,991,898,381,364,377,717,935,897,248,643,804,864,944,620,442,717,146,211,680,865,571,135,123,808,103,942,56,590,876,465,408,319,954,8,225,852,444,124,778,694,279,530,492,554,123,551,348,593,199,429,86,742,393,190,603,577,417,999,470,711,899,590,477,453,937,780,854,258,763,674,43,343,342,161,229,317,62,592,914,21,829,392,112,355,285,384,657,276,894,998,785,455,785,505,715,906,570,236,536,725,62,665,601,589,224,108,131,576,14,396,365,390,692,672,1,694,949,365,841,702,969,879,868,30,281,920,905,378,6,240,417,856,174,779,471,611,210,906,76,629,391,109,893,668,910,156,325,577,743,439,281,44,896,896,493,380,227,582,72,405,151,660,943,403,289,308,467,904,160,144,357,599,639,3,928,554,811,861,25,971,570,285,199,608,94,381,929,749,329,912,311,640,258,937,924,651,634,294,790,512,345,195,840,615,14,238,193,639,174,583,448,25,77,107,461,695,547,900,151,630,468,724,453,239,217,827,366,142,989,529,15,678,836,899,376,573,127,62,482,564,143,880,989,119,333,692,263,970,3,924,589,561,451,984,696,51,929,205,917,159,203,120,762,45,604,229,724,439,488,777,606,786,357,838,397,584,631,617,69,783,458,447,193,699,216,202,567,189,15,328,377,699,157,379,817,101,943,630,610,308,924,107,425,457,803,226,71,477,44,517,688,959,138,585,693,843,927,660,164,37,356,783,785,493,504,562,866,870,3,710,904,442,633,847,223,965,350,160,635,633,629,413,728,311,796,279,865,48,865,783,541,870,960,646,221,289,135,198,444,244,564,368,913,118,938,289,995,671,597,597,137,975,125,312,481,833,987,438,639,98,231,755,652,775,542,90,521,465,722,405,828,386,43,234,70,29,238,282,353,829,822,514,902,986,690,157,611,316,4,224,670,792,442,726,130,608,799,618,726,934,884,328,362,888,306,424,689,940,401,894,177,982,585,198,184,522,313,287,288,621,563,269,139,243,74,786,573,82,191,820,242,876,721,777,313,273,117,599,724,907,414,476,930,21,969,255,301,559,409,611,876,344,296,695,61,438,439,468,237,714,602,992,573,510,590,804,69,6,933,138,166,213,422,502,920,835,52,323,484,764,217,980,337,71,228,723,176,380,137,318,457,142,103,450,534,48,150,102,748,119,700,968,452,858,19,281,122,454,630,336,113,237,198,343,387,422,288,981,142,100,476,548,269,772,117,484,152,118,409,883,531,908,327,498,530,725,396,742,710,685,945,904,838,509,826,946,421,352,815,915,539,737,159,762,797,99,151,628,677,902,56,465,328,864,274,199,780,235,137,757,460,258,24,604,276,451,865,327,249,477,848,328,241,905,725,372,522,12,202,761,277,308,594,360,808,893,911,189,35,922,197,493,370,913,766,692,110,257,121,76,97,26,299,331,393,828,345,89,969,981,661,813,818,595,391,80,72,409,928,381,253,659,248,982,328,783,817,591,424,150,38,818,557,113,354,835,219,975,972,24,774,561,461,521,615,787,549,494,303,212,450,794,157,967,920,344,975,636,340,239,727,7,256,688,882,284,947,179,972,54,220,970,592,247,965,351,241,60,478,261,685,233,249,874,474,855,242,505,551,453,976,527,935,276,993,866,555,38,325,705,313,886,834,292,426,729,605,639,164,74,574,298,466,757,249,582,883,355,425,753,393,108,88,428,435,9,960,184,312,708,199,717,790,367,475,464,348,412,620,507,72,321,863,612,689,745,579,124,433,105,486,167,932,441,582,938,822,879,799,453,354,226,192,71,538,533,840,82,339,448,890,738,197,607,57,213,77,275,197,533,271,729,40,150,159,204,392,988,938,116,260,646,251,323,474,266,887,955,810,212,29,799,793,229,990,354,932,813,774,202,181,232,36,383,451,193,336,1000,626,912,184,704,883,990,894,434,830,649,982,801,184,417,185,478,808,595,738,609,339,703,624,693,998,373,199,407,153,192,850,568,498,773,378,901,718,272,402,868,581,825,998,173,186,374,285,392,759,337,677,666,371,674,109,653,606,919,547,201,449,369,859,245,204,173,304,137,353,244,672,924,983,178,236,206,216,188,466,65,333,285,970,916,430,405,674,212,573,701,706,686,884,66,669,463,434,412,581,159,411,102,939,763,791,992,14,346,709,345,347,702,609,17,883,731,578,609,415,539,12,316,443,488,775,286,75,130,466,440,271,223,460,911,327,429,272,267,282,275,976,860,292,437,587,47,562,75,287,651,531,767,290,224,340,959,411,532,738,660,22,66,763,65,515,526,530,635,941,144,181,43,13,137,655,488,990,493,524,529,202,13,305,721,492,853,675,559,563,165,216,526,549,992,246,564,816,182,263,257,557,141,24,699,78,8,712,248,807,952,290,497,863,530,303,802,423,264,727,907,475,375,538,245,457,325,359,639,351,394,694,602,552,80,564,238,604,643,14,250,584,396,879,362,529,838,183,698,743,372,350,233,609,924,840,433,854,598,870,278,426,922,526,188,883,108,334,479,394,832,180,876,701,541,153,262,711,674,176,750,668,374,868,677,656,618,63,577,358,625,685,637,61,576,267,430,812,384,21,721,398,389,681,170,988,131,299,981,709,655,584,577,114,733,420,802,270,211,793,208,844,112,201,15,204,730,879,266,785,447,492,119,981,775,840,714,725,355,708,930,717,664,741,933,997,359,485,4,506,451,931,148,509,612,510,764,193,722,274,652,166,546,361,187,75,282,272,353,122,417,423,708,379,530,833,594,690,193,928,321,457,875,653,848,788,391,16,113,336,132,180,972,44,887,948,654,840,127,461,322,998,559,426,482,648,45,690,914,614,675,507,727,428,172,435,184,784,591,590,465,543,573,392,472,782,869,453,783,291,765,81,537,282,525,276,402,910,446,915,385,433,344,717,979,507,675,98,268,889,840,947,866,654,147,820,747,535,19,687,303,716,148,581,422,493,340,764,971,705,404,93,279,337,454,414,794,748,113,971,465,939,549,108,851,741,272,636,424,496,212,550,670,644,921,934,877,923,552,92,263,107,749,136,587,425,32,954,454,749,492,660,852,346,350,416,818,179,774,441,593,201,731,783,99,231,429,915,423,67,842,355,283,660,661,987,712,400,789,968,496,665,724,639,546,519,69,938,923,326,570,47,530,953,46,678,702,658,582,583,503,858,594,492,163,775,161,44,846,873,833,653,120,709,177,317,960,2,420,188,78,664,163,853,898,652,5,112,786,944,66,891,483,920,557,502,925,160,508,157,115,483,926,678,323,443,33,64,20,817,754,258,452,58,290,758,421,705,522,832,97,413,33,614,38,941,248,696,115,279,405,294,370,840,352,650,639,87,184,825,608,183,407,246,360,301,229,106,661,759,36,247,774,945,271,354,742,644,365,472,92,517,361,591,514,818,686,292,626,752,361,65,136,826,667,47,1000,938,502,193,196,426,473,899,933,130,968,532,831,251,441,892,170,866,633,113,83,749,481,25,699,833,760,741,731,190,222,405,470,84,202,571,524,786,596,915,716,497,142,173,607,586,331,130,71,435,603,194,104,856,852,212,449,196,975,940,643,797,593,103,976,647,647,259,720,387,835,660,144,508,461,579,882,367,628,909,935,149,919,962,239,481,543,861,173,710,646,13,620,825,806,228,547,804,932,933,715,958,347,143,837,99,521,49,759,58,169,82,653,610,920,563,637,674,662,449,750,713,979,384,195,443,416,186,11,368,199,258,614,555,390,790,960,743,691,766,998,503,8,298,314,13,556,420,329,726,477,122,792,271,7,382,972,950,705,769,90,698,706,800,312,70,94,622,514,22,321,276,148,600,688,530,156,393,74,519,683,864,344,770,774,839,67,905,350,242,276,284,834,384,705,278,140,47,512,716,259,506,338,914,76,735,797,189,305,940,18,341,424,356,253,872,381,827,333,227,705,22,482,971,249,572,160,21,275,147,96,118,661,628,133,911,557,913,220,57,316,62,330,779,339,117,845,750,326,22,83,302,919,680,197,284,554,968,392,31,136,216,152,104,167,414,192,648,991,462,873,816,478,249,850,439,924,418,766,998,833,805,700,3,991,863,689,631,550,861,756,340,135,784,698,599,936,964,635,941,845,47,519,310,489,997,771,182,540,764,663,194,179,123,659,629,783,952,946,901,559,593,141,82,801,611,459,980,518,33,32,705,752,1000,349,363,239,558,289,398,385,235,388,333,353,785,366,21,414,507,501,470,252,429,142,322,181,686,866,50,124,753,548,967,542,518,135,371,184,789,276,862,394,176,631,109,864,683,615,773,803,127,952,150,24,628,374,82,110,911,505,409,228,188,479,396,230,560,896,352,754,611,760,332,548,707,785,451,644,248,123,838,964,58,919,110,855,832,256,88,563,374,22,419,374,271,797,54,294,424,299,501,673,503,137,168,466,531,785,685,496,524,965,400,257,80,347,605,763,313,846,462,321,290,241,468,228,726,222,121,879,713,457,695,659,707,370,504,844,471,247,250,46,660,138,623,563,486,377,695,882,553,541,62,759,243,767,52,516,31,537,815,193,357,236,410,912,756,415,732,834,239,524,641,628,18,619,205,614,232,828,350,997,460,427,622,839,516,602,890,986,901,45,658,428,417,156,772,460,778,926,218,824,101,403,353,874,740,145,420,91,769,16,117,791,733,327,419,643,89,592,835,527,1000,849,337,712,441,392,958,815,188,905,457,336,292,837,725,464,208,863,777,810,35,606,914,686,932,680,599,878,815,419,482,891,1000,90,264,504,894,217,291,498,388,793,860,298,871,976,421,589,551,852,823,2,466,694,371,790,437,256,215,93,876,568,214,779,14,777,71,609,52,580,182,28,239,273,920,300,118,31,385,804,817,573,453,997,428,782,654,697,584,224,689,430,758,714,585,629,666,324,690,68,802,745,426,674,33,820,675,315,380,893,206,941,765,881,430,481,633,48,729,656,937,718,778,339,611,543,568,292,134,832,868,35,992,847,669,347,818,35,410,604,266,794,396,142,547,84,323,994,215,947,18,128,512,258,96,527,589,732,547,535,124,940,838,22,614,882,19,778,868,688,271,569,680,201,512,150,396,331,271,966,864,868,753,483,485,827,239,650,513,699,507,312,431,281,133,463,476,616,888,805,958,35,474,695,861,495,452,810,423,939,583,972,129,294,868,373,782,585,863,175,983,606,434,769,571,840,508,75,346,313,11,198,949,765,296,106,643,35,887,967,790,331,720,377,581,276,75,397,365,628,808,590,690,100,566,597,954,624,55,608,915,454,162,401,453,206,407,673,708,489,592,656,456,49,331,26,567,451,543,973,731,846,183,360,385,391,708,479,569,466,791,456,455,732,447,823,134,58,262,177,190,199,33,645,492,374,718,283,23,574,346,389,764,252,996,352,371,367,886,331,443,64,193,680,273,727,222,705,776,415,262,288,200,432,898,310,864,479,866,875,491,601,714,69,403,428,397,695,383,754,843,850,292,156,474,747,737,966,548,629,959,750,804,146,542,270,742,594,791,174,565,717,582,789,239,317,423,682,244,563,14,31,753,299,338,277,859,617,653,698,698,850,524,687,11,241,356,735,572,351,377,95,834,264,44,322,865,341,678,618,627,470,106,782,473,796,759,482,996,768,637,485,771,590,550,249,504,507,413,300,417,148,929,299,953,30,66,700,283,393,26,148,463,545,636,7,430,782,867,21,110,684,475,139,447,28,678,744,134,228,296,285,12,379,916,507,401,798,902,89,528,143,236,672,433,610,494,988,476,67,454,961,334,432,750,139,962,23,295,343,664,489,519,696,17,928,317,351,947,312,963,175,17,26,341,447,443,425,425,24,736,324,489,285,924,363,66,168,767,960,135,877,207,183,582,153,555,677,312,343,109,672,606,707,835,422,955,62,140,852,243,966,523,13,926,141,556,852,814,298,717,753,279,877,959,559,681,496,892,489,763,591,231,77,601,280,431,869,607,213,375,695,37,191,624,630,481,753,757,152,921,858,641,455,821,310,629,467,280,49,817,191,512,29,693,49,86,635,934,358,417,905,727,687,958,403,27,366,684,99,681,300,934,34,815,204,435,979,840,924,556,151,887,831,31,722,728,18,701,814,385,956,713,616,474,272,492,595,584,763,690,12,336,510,589,181,822,660,416,874,31,316,134,813,235,546,372,333,639,637,306,59,448,626,35,46,115,59,879,74,876,61,92,279,903,204,470,705,125,200,354,948,520,713,168,825,222,143,361,384,435,535,79,124,982,599,565,374,801,232,505,955,103,438,556,420,884,949,241,776,568,797,970,757,779,428,242,128,589,30,591,739,370,734,630,388,467,264,505,532,887,516,782,920,348,536,505,65,33,319,851,122,602,640,693,287,346,228,247,678,754,320,468,164,143,846,961,351,42,653,708,767,301,725,4,276,404,124,518,287,163,250,707,785,555,995,992,762,403,688,438,78,89,414,776,730,374,184,66,467,920,247,904,373,399,160,718,761,946,79,520,241,988,943,209,790,136,15,824,228,753,139,806,783,509,162,991,319,915,559,692,722,934,479,931,796,279,941,394,334,86,144,504,90,697,394,748,887,428,358,733,464,629,274,495,481,818,796,11,76,921,566,700,68,287,99,681,802,698,863,361,163,623,400,748,473,821,136,457,976,339,909,187,591,930,132,777,681,966,713,187,644,23,49,591,272,872,277,431,67,133,290,739,203,765,953,179,661,994,24,682,358,23,129,975,91,335,550,151,612,246,907,712,597,430,385,534,405,853,394,309,875,210,570,581,743,890,326,553,635,17,253,510,961,349,776,853,18,476,753,150,433,766,200,432,83,176,772,533,348,433,487,489,247,852,892,823,677,682,928,407,822,716,717,324,629,94,250,57,522,589,606,55,768,129,800,14,887,157,693,367,962,851,896,576,9,92,142,102,91,840,33,105,761,930,959,807,123,49,120,681,245,643,887,868,753,99,586,438,841,722,830,844,898,213,176,56,827,232,941,539,113,936,543,385,148,457,885,803,188,745,923,895,636,812,718,108,668,192,570,391,252,351,179,474,407,451,531,629,834,448,528,212,176,173,448,805,332,42,953,848,982,361,887,456,800,696,450,648,37,755,540,123,569,175,584,475,52,807,775,778,779,299,402,140,247,430,30,843,815,51,368,257,666,146,895,677,921,258,299,202,430,421,194,56,478,521,612,44,657,130,337,889,379,318,686,229,463,676,844,558,442,131,639,390,547,750,447,740,878,333,502,381,288,747,742,50,703,308,347,222,572,816,949,925,903,582,536,368,195,495,648,96,522,972,105,728,611,207,354,3,829,603,65,696,51,288,734,334,153,864,542,760,837,624,759,884,944,174,539,23,976,951,64,381,498,508,87,31,324,416,889,946,757,197,285,992,509,161,956,796,230,249,191,100,675,840,524,407,733,402,505,417,648,547,130,924,131,10,269,678,513,683,242,792,119,20,405,407,340,931,708,239,923,42,313,198,486,518,805,422,835,897,711,858,418,643,61,913,479,128,406,135,316,355,835,883,793,964,53,413,254,228,637,452,482,850,729,185,440,844,724,861,432,891,617,590,210,636,981,693,332,227,117,441,510,796,353,575,355,855,703,555,715,603,365,695,330,96,116,646,405,558,400,826,226,234,566,536,177,930,417,394,675,170,537,178,223,411,618,926,390,308,120,144,961,98,58,702,23,168,359,710,904,895,759,869,669,830,218,836,140,371,660,424,254,847,691,874,29,302,837,529,114,698,755,282,864,483,656,916,798,672,603,876,633,963,863,942,698,672,146,907,270,562,156,622,473,520,264,623,795,33,401,537,314,894,24,846,564,391,450,152,790,130,484,39,847,157,279,986,716,623,522,251,594,972,668,452,676,215,219,403,303,99,480,16,849,324,250,381,656,896,105,165,357,244,588,857,710,630,741,507,751,332,230,113,825,796,275,147,74,981,169,636,708,841,164,14,917,705,163,282,213,554,635,397,668,188,887,839,9,94,507,907,770,850,347,352,197,64,929,246,154,988,952,734,522,526,216,742,201,553,71,885,942,856,856,950,663,307,239,894,972,739,563,297,314,483,404,276,718,52,412,611,106,115,784,647,909,370,438,838,361,115,133,65,156,546,77,268,628,722,310,823,309,519,356,459,407,899,624,730,124,241,436,401,875,217,424,335,396,291,300,207,355,626,125,348,814,515,567,419,860,505,940,663,190,260,106,234,779,848,627,445,769,720,314,196,502,172,147,260,886,813,902,255,762,785,781,59,54,683,907,719,116,441,931,514,68,464,210,808,272,337,654,108,512,118,685,706,716,585,225,661,163,834,482,206,332,644,456,522,663,473,819,97,794,255,930,673,941,119,972,799,360,372,256,91,230,646,236,261,696,82,537,129,900,257,736,688,688,782,311,880,841,337,876,610,275,691,455,191,643,990,737,548,612,177,424,628,465,213,878,227,24,799,543,746,406,373,39,957,856,849,972,635,58,706,936,788,184,124,235,733,66,526,160,201,535,544,692,235,765,985,319,81,558,300,428,231,472,584,467,625,395,227,355,282,791,844,909,761,979,662,380,140,880,597,540,281,664,655,736,791,65,25,980,524,1000,870,32,82,165,983,827,520,43,133,958,651,153,393,190,264,572,573,706,111,460,464,186,300,407,812,342,577,86,319,342,185,860,93,164,763,195,481,591,228,250,79,275,531,912,115,684,138,469,31,865,137,504,20,327,118,374,297,173,143,271,861,342,114,696,402,929,223,628,197,358,97,222,1,981,577,410,369,979,400,499,295,435,663,671,769,62,425,862,197,950,895,554,147,810,939,468,32,444,759,563,950,277,828,298,720,671,250,24,246,414,8,607,48,241,163,262,362,95,817,379,960,133,756,901,264,836,289,510,297,769,305,176,429,841,327,604,364,303,38,275,536,225,241,830,892,770,306,191,776,333,15,230,40,584,357,644,808,523,49,623,640,866,779,806,589,441,112,559,642,86,998,454,35,61,617,116,735,31,103,617,167,113,800,795,730,866,928,24,942,663,856,121,61,355,541,232,624,301,915,358,147,7,981,699,118,604,18,935,108,926,420,583,454,303,468,121,66,445,941,383,514,492,967,658,616,136,218,682,982,987,231,758,908,908,627,561,69,958,941,3,350,626,287,16,995,263,798,470,655,515,830,519,426,880,577,553,619,957,201,632,706,415,820,865,227,988,958,871,948,659,351,532,992,317,635,715,998,231,919,23,199,444,534,693,317,289,15,728,66,783,141,922,108,982,771,774,196,369,786,4,47,924,452,819,560,885,453,426,180,14,205,606,264,649,599,960,237,556,210,830,109,435,345,411,736,322,815,63,254,400,300,901,84,513,930,346,373,452,598,211,952,344,840,281,167,150,393,658,96,671,702,673,196,270,377,23,639,881,396,799,736,1,745,975,413,851,187,52,377,450,130,57,288,715,298,922,771,466,276,591,497,351,462,383,734,967,835,880,100,884,328,827,741,81,900,509,590,845,216,710,313,2,359,431,961,516,536,584,338,922,702,670,957,452,93,980,611,846,462,36,282,859,718,98,722,531,503,449,828,376,261,664,641,791,749,374,818,920,874,16,856,182,352,587,259,42,66,794,332,321,795,782,311,825,250,683,780,189,626,426,545,412,11,534,56,95,1,160,665,146,778,925,736,47,513,543,930,76,48,896,461,384,83,505,578,760,497,245,639,498,874,809,316,129,739,294,386,45,569,285,247,843,766,734,192,919,160,429,904,693,228,833,353,298,405,971,58,970,377,591,240,922,695,238,342,160,887,510,273,153,383,756,493,282,142,771,958,901,431,876,496,377,619,652,412,100,581,16,202,130,224,391,343,584,83,833,754,286,933,583,589,474,610,547,705,44,305,286,428,759,624,824,113,307,201,562,722,304,297,929,926,711,252,38,786,918,293,34,912,82,142,381,210,475,77,237,498,322,947,844,330,94,998,753,247,671,960,910,310,652,704,211,420,436,781,271,307,504,354,689,793,722,569,696,150,52,416,71,727,608,891,99,448,986,189,365,408,609,262,269,758,720,184,197,218,363,79,499,245,219,408,251,556,561,989,890,437,218,58,522,970,513,751,736,94,541,304,925,608,925,467,615,67,171,908,910,423,669,958,768,818,692,929,671,11,578,529,148,164,719,830,231,273,910,554,401,675,243,346,11,537,428,703,214,227,974,675,960,347,521,44,243,44,178,518,21,767,818,846,596,559,615,832,528,231,333,903,120,75,821,549,272,655,442,19,497,105,790,51,441,613,385,556,259,287,655,272,787,268,230,140,877,578,235,200,364,203,77,175,775,515,797,760,960,189,337,777,5,438,609,464,964,738,187,342,936,772,27,334,859,926,994,740,184,562,935,97,697,902,803,350,541,100,435,469,613,21,450,270,282,205,565,582,973,780,222,906,807,741,410,992,859,790,152,79,864,200,687,527,215,315,701,908,600,789,28,561,418,374,401,697,3,20,979,153,322,487,336,659,636};
  cerr << "expect sth " << s.jump(loadtestBig) << endl;

  vector<int> wrongAnswer = {1,2,1,1,1};
  cerr << "expect 3 " << s.jump(wrongAnswer) << endl;
  return 0;
}