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
        boost::filesystem::create_directories("tree_test/my_folder");
        boost::filesystem::ofstream( "tree_test/a.cpp" );
    }

    void TearDown() {
        boost::filesystem::remove_all("tree_test");
    }
};


