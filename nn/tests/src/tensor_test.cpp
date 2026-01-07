#include<nn/tensor_test.hpp>

TEST_F(TensorTest, GetItem_On_Scalar) {
	ASSERT_TRUE(t0);
	EXPECT_FLOAT_EQ(t0->getItem(), 1.0f);
}

TEST_F(TensorTest, GetItem_On_ConstScalar) {
	const nd::nn::Tensor t{1.0f};
	const float& ct = t.getItem();
	EXPECT_FLOAT_EQ(ct, 1.0f);
}

TEST_F(TensorTest, InvalidArgument_When_CallOperator_Called_On_Scalar) {
	ASSERT_TRUE(t0);
	EXPECT_THROW({
		(*t0)(0);		
	},std::invalid_argument);
}

TEST_F(TensorTest, RuntimeErrorExc_When_GetItem_Called_On_NonScalar) {
	ASSERT_TRUE(t1);
	EXPECT_THROW({
			(*t1).getItem();
	}, std::runtime_error);
}

TEST_F(TensorTest, RuntimeError_Whet_GetItemConst_Called_On_NonScalar) {
	const nd::nn::Tensor t{data};
	EXPECT_THROW({
			const float& ct = t.getItem();
	}, std::runtime_error);

}
