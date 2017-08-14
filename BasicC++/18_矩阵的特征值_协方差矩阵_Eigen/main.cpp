#include <Eigen/dense>
#include <iostream>
#include <glm/glm.hpp>

//���������ο�����:https://wenku.baidu.com/view/09b2dd362f60ddccda38a0fc.html
const int g_Dimension = 6;

void computeEigenVector(Eigen::MatrixXd vInfluenceMatrix)
{
	_ASSERT(vInfluenceMatrix.rows() == vInfluenceMatrix.cols());

	//Eigen::EigenSolver<Eigen::Matrix<double, g_Dimension, g_Dimension>> EigenSolver1(vInfluenceMatrix);��������������ȷ������ά�ȵ����
	Eigen::EigenSolver<Eigen::MatrixXd> EigenSolver(vInfluenceMatrix);//Eigen::EigenSolver<Eigen::Matrix<double, 4, 3>> ����ʱ�������������������ֵ����

	Eigen::MatrixXcd EigenVectors = EigenSolver.eigenvectors();//��ȡ������������  c��ʾ���Ӿ���
	Eigen::MatrixXcd EigenValues  = EigenSolver.eigenvalues();//��ȡ��������ֵ

	Eigen::MatrixXd EigenValueReal = EigenValues.real();//��ȡ����ֵ��ʵ������  ע������ûc

	Eigen::MatrixXf::Index EigenValuesMax;
	EigenValueReal.rowwise().sum().maxCoeff(&EigenValuesMax);//�õ��������ֵ��λ��

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

	Eigen::MatrixXd CovMat = computeCovMat(TestMatrix);//Э�������һ����󼴿ɣ�
	for (unsigned int i=0; i<CovMat.rows(); ++i)
	{
		for (unsigned int k=0; k<CovMat.cols(); ++k)
		{
			std::cout << CovMat(i, k) << " ";
		}
		std::cout << std::endl;
	}

	computeEigenVector(TestMatrix);//ֻ�з������������ֵ����������

	system("pause");

	return 0;
}