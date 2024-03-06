#include "Dc.hpp"
#include <gtest/gtest.h>

namespace rosneuro {

template <typename T>
class DcTest : public Dc<T> {
    public:
        DcTest() : Dc<T>() {};
        ~DcTest() {};
};

class DcTestSuite : public ::testing::Test {
    public:
        DcTestSuite() {};
        ~DcTestSuite() {};
        virtual void SetUp() { dc = new DcTest<double>(); };
        virtual void TearDown() { delete dc; };
        DcTest<double>* dc;
};

TEST_F(DcTestSuite, Constructor) {
    ASSERT_EQ(dc->name_, "dc");
}

TEST_F(DcTestSuite, Configure) {
    ASSERT_TRUE(dc->configure());
}

TEST_F(DcTestSuite, Apply) {
    Eigen::Matrix<double, 3, 3> input_matrix;
    input_matrix << 1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0,
                    7.0, 8.0, 9.0;

    auto result_matrix = dc->apply(input_matrix);
    ASSERT_EQ(result_matrix.rows(), 3);
    ASSERT_EQ(result_matrix.cols(), 3);

    for (int i = 0; i < result_matrix.cols(); ++i)
        ASSERT_NEAR(result_matrix.col(i).mean(), 0.0, 1e-6);
}

}

int main(int argc, char **argv) {
    ros::init(argc, argv, "DcTestSuite");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}