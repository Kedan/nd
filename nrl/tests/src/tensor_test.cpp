#include<nrl/tensor_test.hpp>

std::vector<float> TensorGetter::getFlatternData() const {
	return m_data;
}


TEST_F(TensorTest, Construct_Scalar) {
	nd::nrl::Tensor<float> tensor{5.0f};
	EXPECT_EQ(tensor.getShape(), std::vector<std::size_t>{});
	EXPECT_THROW(tensor(0), std::invalid_argument);
	EXPECT_EQ(tensor.getItem(), 5.0f);
}

TEST_F(TensorTest, Construct_1D) {
	std::vector<float> v = {1.0f, 2.3f, 3.45f};
	nd::nrl::Tensor<float> tensor{v};
	EXPECT_EQ( tensor.getShape(), std::vector<std::size_t>{3});
	EXPECT_FLOAT_EQ(tensor(0), 1.0f);
	EXPECT_FLOAT_EQ(tensor(1), 2.3f);
	EXPECT_FLOAT_EQ(tensor(2), 3.45f);
	EXPECT_THROW(tensor(3), std::invalid_argument);
	EXPECT_THROW(tensor.getItem(), std::runtime_error);
}

//TEST_F(TensorTest, Construct_2D) {
//	std::vector<std::vector<std::size_t>> v = {
//		{ 1.0f, 2.1f, 3.12f },
//		{ 4,123f, 5.1234f, 6.12345f }
//	};
//	nd::nn::Tensor tensor(v);
//	EXPECT_EQ( tensor.shape(), std::vector<std::size_t>{3,2});
//}

TEST_F(TensorTest, GetItem_On_Scalar) {
	ASSERT_TRUE(t0);
	EXPECT_FLOAT_EQ(t0->getItem(), 1.0f);
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
	const nd::nrl::Tensor t{data};
	EXPECT_THROW({
			const float& ct = t.getItem();
	}, std::runtime_error);

}

TEST_F(TensorTest, Addition_Scalar_plus_Scalar) {
	using tf = nd::nrl::Tensor<float>;
	std::shared_ptr<tf> a = std::make_shared<tf>(1.f);
	std::shared_ptr<tf> b = std::make_shared<tf>(1.f);
	std::shared_ptr<tf> c = (*a) + b; 

	EXPECT_FLOAT_EQ(c->getItem(), 2.f);
}
//
//TEST_F(TensorTest, Flattern_Tensor_Data) {
//	TensorGetter t{data2d};
//	std::vector<std::size_t> shape_proto{3, 3};
//	std::vector<std::size_t> stride_proto{3 ,1};
//	std::vector<float> data_proto{1.f, 2.f,3.f, 4.f, 5.f , 6.f, 7.f, 8.f, 9.f};
//
//	std::vector<std::size_t> shape = static_cast<std::vector<std::size_t>>(t.getShape());
//	std::vector<float>  flatData = t.getFlatternData();
//	std::vector<std::size_t> stride = t.getStride();
//
//	EXPECT_EQ(shape, shape_proto);
//	EXPECT_EQ(stride, stride_proto);
//	EXPECT_EQ(flatData, data_proto);
//}
