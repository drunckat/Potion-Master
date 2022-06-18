#include <fstream>
#include <iostream>
#include <iomanip>

#include "ingridients.h"

IngridientVector ingridientVector;

void IngridientBags::fill(string filePath) {
        ifstream data(filePath);
        
        try {
	      while (!data.eof()) {
		    int index;
		    uint64_t amount;
		    string name;
		    data >> index >> name >> amount;
		    if (amount > 0) {
			  collection.push_back(
				{ ingridientVector[index], name, amount, static_cast<IngridientsName>(index) });
		    }
	      }
        }
        catch (std::exception e) {
	      throw e;
        }
}

array<vector<Mix>, 6> Combinator::mix_creator(IngridientBags bag) {
        array<vector<Mix>, 6> mixes;
        if (bag.collection.size() > 2)
        for (auto iterator1 = bag.collection.cbegin(); iterator1 < bag.collection.cend() - 2; iterator1++) {
	      for (auto iterator2 = iterator1 + 1; iterator2 < bag.collection.cend() - 1; iterator2++) {
		    for (auto iterator3 = iterator2 + 1; iterator3 < bag.collection.cend(); iterator3++) {
			  uint8_t points = 0;
			  bool is_positive = false;
			  bool is_negative = false;
			  bool i_is_useful = false;
			  bool j_is_useful = false;
			  bool l_is_useful = false;
			  unordered_set<EffectsName> setEffects;

			  for (auto i : iterator1->ingridient.effect) {
				for (auto j : iterator2->ingridient.effect) {
				        if (i == j) {
					      i_is_useful = true;
					      j_is_useful = true;
					      if (i.first == ClassEffect::Positive) {
						    is_positive = true;
					      }
					      else {
						    is_negative = true;
					      }
					      if (is_negative and is_positive) {
						    goto MixIsNotUseful;
					      }
					      else {
						    setEffects.insert(i.second);
						    points++;
					      }
				        }
				}
			  }
			  for (auto i : iterator2->ingridient.effect) {
				for (auto j : iterator3->ingridient.effect) {
				        if (i == j) {
					      if (i.first == ClassEffect::Positive) {
						    is_positive = true;
					      }
					      else {
						    is_negative = true;
					      }
					      if (is_negative and is_positive) {
						    goto MixIsNotUseful;
					      }
					      else {
						    if (!setEffects.count(i.second)) {
							  setEffects.insert(i.second);
							  points++;
							  j_is_useful = true;
							  l_is_useful = true;
						    }
					      }
				        }
				}
			  }
			  for (auto i : iterator1->ingridient.effect) {
				for (auto j : iterator3->ingridient.effect) {
				        if (i == j) {
					      if (i.first == ClassEffect::Positive) {
						    is_positive = true;
					      }
					      else {
						    is_negative = true;
					      }
					      if (is_negative and is_positive) {
						    goto MixIsNotUseful;
					      }
					      else {
						    if (!setEffects.count(i.second)) {
							  setEffects.insert(i.second);
							  points++;
							  i_is_useful = true;
							  l_is_useful = true;
						    }
					      }
				        }
				}
			  }
			  if (i_is_useful and j_is_useful and l_is_useful) {
				Mix mix;
				mix.parts = { *iterator1, *iterator2, *iterator3 };
				mix.points = points;
				mixes[points - 1].push_back(mix);
			  }
		    MixIsNotUseful:;
		    }
	      }
        }
        if (bag.collection.size() > 1)
        for (auto iterator1 = bag.collection.cbegin(); iterator1 < bag.collection.cend() - 1; iterator1++) {
	      for (auto iterator2 = iterator1 + 1; iterator2 < bag.collection.cend(); iterator2++) {
		    uint8_t points = 0;
		    bool is_positive = false;
		    bool is_negative = false;
		    for (auto i : iterator1->ingridient.effect) {
			  for (auto j : iterator2->ingridient.effect) {
				if (i == j) {
				        if (i.first == ClassEffect::Positive) {
					      is_positive = true;
				        }
				        else {
					      is_negative = true;
				        }
				        if (is_negative and is_positive) {
					      goto MixIsNotUseful2;
				        }
				        else {
					      points++;
				        }
				}
			  }
		    }
		    if (points) {
			  Mix mix;
			  mix.parts = { *iterator1, *iterator2};
			  mix.points = points;
			  mixes[points - 1].push_back(mix);
		    }
	      MixIsNotUseful2:;
	      }
        }
        return mixes;
}

uint64_t Mix::min() {
        uint64_t min = UINT64_MAX;
        for (auto& x : parts) {
	      min = x.count < min ? x.count : min;
        }
        return min;
}

Combinator::Combinator(IngridientBags bag) {
        auto mix = mix_creator(bag);
        for (int8_t i = 5; i >= 0; i--) {
	      while (!mix[i].empty()) {
		    string three_ingridients;
		    array<uint64_t, 6> loss_per_points_level_the_best = { UINT64_MAX, UINT64_MAX, UINT64_MAX, UINT64_MAX, UINT64_MAX, UINT64_MAX };
		    std::array<vector<Mix>, 6> newMix;
		    for (auto x : mix[i]) {
			  auto copyMix = mix;
			  vector<IngridientsName> parts;
			  string name;
			  for (auto y : x.parts) {
				if (name.empty()) {
				        name += y.name;
				}
				else {
				        name += " - ";
				        name += y.name;
				}
			  }
			  array<uint64_t, 6> loss_per_points_level_current = { 0, 0, 0, 0, 0, 0 };
			  for (int8_t j = i; j >= 0; j--) {
				for (uint64_t z = 0; z < copyMix[j].size(); z++) {
				        bool lossExists = false;
				        for (auto k : x.parts) {
					      for (auto& part : copyMix[j][z].parts) {
						    if (k == part) {
							  lossExists = true;
							  part.count--;
						    }
					      }
				        }
				        if (lossExists) {
					      loss_per_points_level_current[j] += copyMix[j][z].points;
					      if (copyMix[j][z].min() == 0) {
						    copyMix[j].erase(copyMix[j].cbegin() + z);
						    z--;
					      }
				        };
				}
			  }
			  for (int8_t j = i; j >= 1; j--) {
				if (loss_per_points_level_current[j] < loss_per_points_level_the_best[j]) {
				        loss_per_points_level_the_best = loss_per_points_level_current;
				        three_ingridients = name;
				        newMix = copyMix;
				        goto endForThisMix;
				}
				else if (loss_per_points_level_current[j] > loss_per_points_level_the_best[j]) {
				        goto endForThisMix;
				}
			  }
			  if (loss_per_points_level_current[0] <= loss_per_points_level_the_best[0]) {
				loss_per_points_level_the_best = loss_per_points_level_current;
				three_ingridients = name;
				newMix = copyMix;
				goto endForThisMix;
			  }
			  endForThisMix:;
		    }	 
		    mix = newMix;
		    if (combination.count(three_ingridients)) {
			  combination[three_ingridients]++;
		    }
		    else {
			  combination.insert({ three_ingridients, 1 });
		    }
	      }
        }
}

void Combinator::show () {
        cout << endl;
        for (auto& x : combination) {
	      cout << setw(40) << x.first;
	      cout << " x" << x.second << endl;
        }
}