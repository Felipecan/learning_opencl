#include <iostream>
#include <CL/cl.h>
#include "Error.h"


int main()
{

    cl_int err;

    cl_platform_id *platforms;
    cl_uint num_platforms;
    cl_platform_info param_name_platform[] = {CL_PLATFORM_PROFILE, CL_PLATFORM_VERSION, CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_EXTENSIONS};


    cl_device_id *devices;
    cl_uint num_devices;
    cl_device_info param_name_device[] = {CL_DEVICE_TYPE, CL_DEVICE_NAME, CL_DEVICE_VENDOR, CL_DEVICE_VERSION, CL_DEVICE_EXTENSIONS, CL_DEVICE_MAX_COMPUTE_UNITS,
                                            CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, CL_DEVICE_MAX_WORK_ITEM_SIZES, CL_DEVICE_MAX_WORK_GROUP_SIZE, CL_DEVICE_GLOBAL_MEM_SIZE,
                                            CL_DEVICE_MAX_CLOCK_FREQUENCY, CL_DEVICE_ADDRESS_BITS, CL_DEVICE_MAX_MEM_ALLOC_SIZE,
                                            CL_DEVICE_MAX_PARAMETER_SIZE, CL_DEVICE_IMAGE_SUPPORT, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE};




    err = clGetPlatformIDs(1, NULL, &num_platforms);
    error(err, __LINE__);
    platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * num_platforms);
    err = clGetPlatformIDs(num_platforms, platforms, NULL);
    error(err, __LINE__);

    std::cout<<"Number of platforms: "<<num_platforms<<"\n\n";

    for(int i = 0; i < num_platforms; i++)
    {

        std::cout<<"\tPlatform information "<<i+1<<"\n\n";

        size_t info_size;

        for(int j = 0; j < (sizeof(param_name_platform)/sizeof(cl_platform_info)); j++)
        {

            err = clGetPlatformInfo(platforms[i], param_name_platform[j], 0, NULL, &info_size);
            error(err, __LINE__);
            char *info = (char*) malloc(sizeof(char) * info_size);
            err = clGetPlatformInfo(platforms[i], param_name_platform[j], info_size, info, NULL);
            error(err, __LINE__);

            if(j == 0)
            {

                std::cout<<"\t\tPlatfom Profile: "<<info<<"\n\n";

            }

            if(j == 1)
            {

                std::cout<<"\t\tPlatfom Version: "<<info<<"\n\n";

            }

            if(j == 2)
            {

                std::cout<<"\t\tPlatfom Name: "<<info<<"\n\n";

            }

            if(j == 3)
            {

                std::cout<<"\t\tPlatfom Vendor: "<<info<<"\n\n";

            }

            if(j == 4)
            {

                std::cout<<"\t\tPlatfom Extensions: "<<info<<"\n\n";

            }

        }

        err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
        error(err, __LINE__);
        devices = (cl_device_id*) malloc(sizeof(cl_device_id) * num_devices);
        err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
        error(err, __LINE__);


        std::cout<<"\n\n\nPlatform "<<i+1<<"\n\n";
        std::cout<<"\tNumber of devices: "<<num_devices<<"\n\n";

        for(int k = 0; k < num_devices; k++)
        {

            std::cout<<"\t\tDevice information "<<k+1<<"\n\n";

            for(int v = 0; v < (sizeof(param_name_device)/sizeof(cl_device_info)); v++)
            {

                if(v == 0)
                {

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    cl_device_type *info = (cl_device_type*) malloc(sizeof(cl_device_type) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice type: "<<info<<"\n\n";
                    free(info);

                }

                if(v == 1)
                {

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    char *info = (char*) malloc(sizeof(char) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice name: "<<info<<"\n\n";
                    free(info);

                }

                if(v == 2)
                {

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    char *info = (char*) malloc(sizeof(char) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice vendor: "<<info<<"\n\n";
                    free(info);

                }

                if(v == 3)
                {

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    char *info = (char*) malloc(sizeof(char) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice version: "<<info<<"\n\n";
                    free(info);

                }

                if(v == 4)
                {

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    char *info = (char*) malloc(sizeof(char) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice extensions: "<<info<<"\n\n";
                    free(info);

                }

                if(v == 5)
                {

                    cl_uint info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max computer units: "<<info<<"\n\n";

                }

                if(v == 6)
                {

                    cl_uint info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max work item dimensions: "<<info<<"\n\n";

                }

                if(v == 7)
                {

                    cl_uint aux;
                    err = clGetDeviceInfo(devices[k], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, info_size, &aux, NULL);
                    error(err, __LINE__);

                    err = clGetDeviceInfo(devices[k], param_name_device[v], 0, NULL, &info_size);
                    error(err, __LINE__);
                    size_t *info = (size_t*) malloc(sizeof(size_t) * info_size);
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, info, NULL);
                    error(err, __LINE__);

                    std::cout<<"\t\t\tDevice max work item sizes:\n";
                    for(int w = 0; w < aux; w++)
                    {

                        std::cout<<"\t\t\t\t\t\t    Work item["<<w+1<<"]: "<<info[w]<<"\n\n";

                    }

                }

                if(v == 8)
                {

                    size_t info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max work group sizes: "<<info<<"\n\n";

                }

                if(v == 9)
                {
                    cl_ulong info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice global mem size: "<<info/1048576<<" Mb\n\n";

                }

                if(v == 10)
                {

                    cl_uint info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max clock frequency: "<<info<<" MHz\n\n";

                }

                if(v == 11)
                {

                    cl_uint info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice Address bit: "<<info<<"\n\n";

                }

                if(v == 12)
                {

                    cl_ulong info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max mem alloc size: "<<info/1048576<<" Mb \n\n";

                }

                if(v == 13)
                {

                    size_t info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice max parameter size: "<<info<<"\n\n";

                }

                if(v == 14)
                {

                    cl_bool info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    if(info)
                    {

                        std::cout<<"\t\t\tDevice image support: Yes \n\n";

                    }
                    else
                    {

                        std::cout<<"\t\t\tDevice image support: Yes \n\n";

                    }

                }

                if(v == 15)
                {

                    cl_ulong info;
                    err = clGetDeviceInfo(devices[k], param_name_device[v], info_size, &info, NULL);
                    error(err, __LINE__);
                    std::cout<<"\t\t\tDevice global mem cache size: "<<info<<" B\n\n";

                }

            }

        }

    }

}
