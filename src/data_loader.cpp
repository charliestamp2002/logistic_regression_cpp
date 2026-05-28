#include "data_loader.h"

#include <fstream>
#include <sstream>
#include <iostream>

DataLoader::DataLoader(const std::string& filepath)
    :filepath_(filepath) {}

    bool DataLoader::load_data() {

        std::ifstream file(filepath_);

        if (!file.is_open()) {
            std::cerr << "Error opening file" << filepath_ << std::endl;
            return false;
        }

        std::string line;

        while (std::getline(file, line)) {
            std::vector<double> row = parse_line(line);

            if (row.empty()) continue;

            std::vector<double> features;

            for (size_t i = 0; i < row.size() - 1; i++){
                features.push_back(row[i]);
            }

            X_.push_back(features);
            y_.push_back(row.back());
        
        }

        return true;
    
    }

    std::vector<double> DataLoader::parse_line(const std::string& line) { 
        std::vector<double> result;
        std::stringstream ss(line);
        std::string cell;
        
        while (std::getline(ss, cell, ',')) {
            try{
                result.push_back(std::stod(cell));
            } catch (...) {
                std::cerr << "Error parsing cell:" << cell << std::endl;
                return {};
            }
        }

        return result;
    }

    const std::vector<std::vector<double>>& DataLoader::get_features() const{
        return X_;
    }

    const std::vector<double>& DataLoader::get_targets() const {
        return y_;
    }



