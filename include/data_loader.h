#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <string>
#include <vector>

class DataLoader { 
    public: 
    DataLoader(const std::string& filepath);

    const std::vector<std::vector<double>>& get_features() const;
    const std::vector<double>& get_targets() const;

    bool load_data();


    private:
    std::string filepath_;

    std::vector<std::vector<double>> X_;
    std::vector<double> y_;
    
    std::vector<double> parse_line(const std::string& filepath);

};

#endif

