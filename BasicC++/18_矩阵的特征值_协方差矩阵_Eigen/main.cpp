#include <Eigen/dense>
#include <iostream>
#include <glm/glm.hpp>

//特征向量参考资料:https://wenku.baidu.com/view/09b2dd362f60ddccda38a0fc.html
const int g_Dimension = 6;

void computeEigenVector(Eigen::MatrixXd vInfluenceMatrix)
{
	_ASSERT(vInfluenceMatrix.rows() == vInfluenceMatrix.cols());

	//Eigen::EigenSolver<Eigen::Matrix<double, g_Dimension, g_Dimension>> EigenSolver1(vInfluenceMatrix);这种适用于事先确定矩阵维度的情况
	Eigen::EigenSolver<Eigen::MatrixXd> EigenSolver(vInfluenceMatrix);//Eigen::EigenSolver<Eigen::Matrix<double, 4, 3>> 运行时报错！！方阵才能求特征值！！

	Eigen::MatrixXcd EigenVectors = EigenSolver.eigenvectors();//获取矩阵特征向量  c表示复杂矩阵
	Eigen::MatrixXcd EigenValues  = EigenSolver.eigenvalues();//获取矩阵特征值

	Eigen::MatrixXd EigenValueReal = EigenValues.real();//获取特征值的实数部分  注意这里没c

	Eigen::MatrixXf::Index EigenValuesMax;
	EigenValueReal.rowwise().sum().maxCoeff(&EigenValuesMax);//得到最大特征值的位置

	for (unsigned int i=0; i<vInfluenceMatrix.cols(); ++i)
	{
		std::cout << EigenVectors.real()(i, EigenValuesMax) << " ";
	}
	std::cout << std::endl;

	Eigen::VectorXd EigenVector(vInfluenceMatrix.cols());
	for (unsigned int i=0; i<vInfluenceMatrix.cols(); ++i)
	{
		EigenVector(i) = EigenVectors.real()(i, EigenValuesMax);
	}
	std::cout << EigenVector << std::endl;

	EigenVector.normalize();
	std::cout << EigenVector << std::endl;
	glm::vec2 Test(EigenVector.x(), EigenVector.y());
	glm::normalize(Test);
	std::cout << Test.x << " " << Test.y << std::endl;
}

Eigen::MatrixXd computeCovMat(Eigen::MatrixXd vMatrix)
{
	Eigen::MatrixXd MeanVec = vMatrix.colwise().mean();
	Eigen::RowVectorXd MeanVecRow(Eigen::RowVectorXd::Map(MeanVec.data(), vMatrix.cols()));

	Eigen::MatrixXd ZeroMeanMat = vMatrix;
	ZeroMeanMat.rowwise() -= MeanVecRow;

	Eigen::MatrixXd CovMat;
	if (vMatrix.rows() == 1)
	{
		CovMat = (ZeroMeanMat.adjoint() * ZeroMeanMat) / double(vMatrix.rows());
	}
	else
	{
		CovMat = (ZeroMeanMat.adjoint() * ZeroMeanMat) / double(vMatrix.rows() -1);
	}

	return CovMat;
}


int main()
{
	Eigen::MatrixXd TestMatrix(2, 2);
	TestMatrix <<  3, -1,
		          -1, 3;

	// 	TestMatrix << -2,   1,  0, 1,
	// 		           0,  -2,  1, 0,
	// 		           0,   0, -1, -1;

	Eigen::MatrixXd CovMat = computeCovMat(TestMatrix);//协方差矩阵（一般矩阵即可）
	for (unsigned int i=0; i<CovMat.rows(); ++i)
	{
		for (unsigned int k=0; k<CovMat.cols(); ++k)
		{
			std::cout << CovMat(i, k) << " ";
		}
		std::cout << std::endl;
	}

	computeEigenVector(TestMatrix);//只有方阵才能求特征值和特征向量

	system("pause");

	return 0;
}