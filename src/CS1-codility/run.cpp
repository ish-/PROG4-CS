#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <set>

using namespace std;
namespace fs = std::filesystem;

int main() {
  string folderPath = "./"; // Specify the folder path with executables

  std::set<fs::path> sortedPathes;

  for (const auto& entry : fs::directory_iterator(folderPath)) {
    if (entry.is_regular_file()) {
      auto path = entry.path();
      string fileName = path.filename().string();
      string filePath = path.string();

      // cout << "fileName: " << fileName << endl;

      if (fileName.starts_with("CS1-"s) && !fileName.ends_with("_RUN"s))
        sortedPathes.insert(filePath);
    }
  }

  for (const auto& filePath : sortedPathes) {
    std::cout  << '\n'<< "Running: " << filePath << '\n';
    int result = system(filePath.c_str());

    if (result == -1) {
      std::cerr << "Error running executable: " << filePath << '\n';
    }
  }

  return 0;
}