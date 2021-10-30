// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "FPSProjectProjectile.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	// 指定Mesh，也可在编辑器修改
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// 浮空动作
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * FloatSpeed;          //按FloatSpeed调整高度
	float DeltaRotation = DeltaTime * RotationSpeed;    //每秒旋转等于RotationSpeed的角度

	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);


	// 调用碰撞事件
	VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &AFloatingActor::CheckActor);

}


void AFloatingActor::CheckActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 把OtherActor（碰撞到FlotingActor的物体）转换成Projectile类型
	// 如果转换成功，则说明跟子弹类发生了碰撞
	AFPSProjectProjectile* projectile = Cast<AFPSProjectProjectile>(OtherActor);

	// 如果跟子弹发生碰撞，则双方销毁
	if (projectile == nullptr)
	{
		return;
	}
	else
	{
		OtherActor->Destroy();
		this->Destroy();
	}


}
