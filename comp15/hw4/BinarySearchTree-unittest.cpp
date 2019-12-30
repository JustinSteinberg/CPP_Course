/*
 * BinarySearchTree-unittest.cpp
 * COMP15
 * Spring 2019
 * 
 * Small unit test for the Binary Search Tree class using google Test 
 *
 */

#include "BinarySearchTree.h"
#include <gtest/gtest.h>
#include <limits>
#include <vector>

// some sanity check unit tests

class BSTtests : public ::testing::Test {
protected:
/**
 * This a TEST Fixture in Google Test. It is used to define data that
 * many tests can use. Each test gets its own copy of the same data.
 * Here, We define a testdata vector with some predefined numbers
 * The array is initialized in the constructor. No clean up is needed.
**/
        const std::vector<int> testdata;
        BSTtests()
            : testdata{258,  579,  814, -566, -686, -3,  -600,
                       382,  -562, -55, -768, 172,  252, 397,
                       -155, -898, 430, -520, 154,  255} {}
};

/*
 * Unit testing for find_min
 */
TEST_F(BSTtests, find_min) {
        BinarySearchTree bst;
        constexpr int    errorVal    = std::numeric_limits<int>::min();
        constexpr int    testdataMin = -898;

        // We start testng an edge case: find the 
        // minimum in an empty tree
        EXPECT_EQ(bst.find_min(), errorVal)
            << "find_min on an empty tree should"
               " return INT_MIN";

        // edge case: root is min
        bst.insert(0);
        EXPECT_EQ(bst.find_min(), 0);

        for (int num : testdata)
                bst.insert(num);

        // typical usage: we look for minimum after inserting many numbers
        EXPECT_EQ(bst.find_min(), testdataMin);
}

/*
 * Unit testing for find_max
 */
TEST_F(BSTtests, find_max) {
        BinarySearchTree bst;
        constexpr int    errorVal    = std::numeric_limits<int>::max();
        constexpr int    testdataMax = 814;

        // We start testng an edge case: find the
        // maximum in an empty tree
        EXPECT_EQ(bst.find_max(), errorVal)
            << "find_max on an empty tree should"
               " return INT_MAX";

        // edge case: root is min
        bst.insert(0);
        EXPECT_EQ(bst.find_max(), 0);

        for (int num : testdata)
                bst.insert(num);

        // typical usage: we look for maximum after inserting many numbers
        EXPECT_EQ(bst.find_max(), testdataMax);
}

/*
 * Unit	testing	for remove
 */

TEST_F(BSTtests, remove) {
        BinarySearchTree bst;
       // constexpr int    errorVal    = std::numeric_limits<int>::max();
        constexpr bool   testdataIn = true;

        // We start testng an edge case: 
        // remove in an empty tree
        EXPECT_EQ(bst.remove(-55), false)
            << "remove on an empty tree should"
               " return false";

        // edge case: root is min
        bst.insert(0);
        EXPECT_EQ(bst.remove(-55), 0);

        for (int num : testdata)
                bst.insert(num);

        // typical usage: remove certain number after inserting many numbers
        EXPECT_EQ(bst.remove(-55), testdataIn);
}

/*
 * Unit testing for contains
 */

TEST_F(BSTtests, contains) {
        BinarySearchTree bst;
       // constexpr int    errorVal    = std::numeric_limits<int>::max();
        constexpr bool   testdataIn = true;

        // We start testng an edge case: find the
        // maximum in an empty tree
        EXPECT_EQ(bst.contains(-55), false)
            << "contains on an empty tree should"
               " return false";

        // edge case: root is min
        bst.insert(0);
        EXPECT_EQ(bst.contains(-55), 0);

        for (int num : testdata)
                bst.insert(num);

        // typical usage: we look for certain number after inserting many numbers
        EXPECT_EQ(bst.contains(-55), testdataIn);
}

