#include<nn/tensor_test.hpp>

std::vector<float> TensorGetter::getFlatternData() const {
	return m_data;
}

std::vector<std::size_t> TensorGetter::getStride() const {
	return m_stride;
}

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

TEST_F(TensorTest, Flattern_Tensor_Data) {
	TensorGetter t{data2d};
	std::vector<std::size_t> shape_proto{3, 3};
	std::vector<std::size_t> stride_proto{3 ,1};
	std::vector<float> data_proto{1.f, 2.f,3.f, 4.f, 5.f , 6.f, 7.f, 8.f, 9.f};

	std::vector<std::size_t> shape = static_cast<std::vector<std::size_t>>(t.getShape());
	std::vector<float>  flatData = t.getFlatternData();
	std::vector<std::size_t> stride = t.getStride();

	EXPECT_EQ(shape, shape_proto);
	EXPECT_EQ(stride, stride_proto);
	EXPECT_EQ(flatData, data_proto);
}
