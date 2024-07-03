from setuptools import find_packages, setup

package_name = 'action_robo_v1'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=[
        'setuptools',
        'paho-mqtt',
        'rclpy',
    ],
    zip_safe=True,
    maintainer='iartes',
    maintainer_email='bruna.mariana@icomp.ufam.edu.br',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robo_action_server  = action_robo_v1.robo_action_server:main',
            'robo_action_client  = action_robo_v1.robo_action_client:main'
        ],
    },
)
