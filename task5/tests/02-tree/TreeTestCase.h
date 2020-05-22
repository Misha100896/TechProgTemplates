//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>


class TreeTestCase : public ::testing::Test {
protected:
    void SetUp() {
        auto tmpDir = boost::filesystem::temp_directory_path().string();
        boost::filesystem::create_directories(tmpDir + "/tree_test/my_folder");
        boost::filesystem::ofstream( tmpDir + "/tree_test/a.cpp" );
    }

    void TearDown() {
        auto tmpDir = boost::filesystem::temp_directory_path().string();
        boost::filesystem::remove_all(tmpDir + "/tree_test");
    }
};


