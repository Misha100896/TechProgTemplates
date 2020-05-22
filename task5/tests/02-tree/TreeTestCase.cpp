//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <iostream>

TEST_F(TreeTestCase, InvalidArg) {
    ASSERT_THROW(GetTree("abacaba", true), std::invalid_argument);
    ASSERT_THROW(GetTree("tree_test/a.cpp", true), std::invalid_argument);
}

TEST_F(TreeTestCase, CheckTreeOnlyDirs) {
    auto tmpDir = boost::filesystem::temp_directory_path().string();

    FileNode node1;
    node1.name = "tree_test";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "my_folder";
    node2.is_dir = true;

    node1.children.push_back(node2);

    ASSERT_EQ(GetTree(tmpDir + "/tree_test", true), node1);
}

TEST_F(TreeTestCase, CheckTreeWithFiles) {
    auto tmpDir = boost::filesystem::temp_directory_path().string();

    FileNode node1;
    node1.name = "tree_test";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "my_folder";
    node2.is_dir = true;

    FileNode node3;
    node3.name = "a.cpp";
    node3.is_dir = false;

    node1.children.push_back(node3);
    node1.children.push_back(node2);

    ASSERT_EQ(GetTree(tmpDir + "/tree_test", false), node1);
}
